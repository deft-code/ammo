#include "ammo/network/netpeer.hpp"

#include <iostream>

// The length of time the peer has to send any final packets
// when it is destroyed
#define PEER_SHUTDOWN_DELAY (100)
// How long the peer waits each heartbeat
// Increase this if the game needs more priority
#define PEER_HEARTBEAT_DELAY (0) 
namespace ammo
{

  /// Creates an instance of NetPeer
  /// @param parent The client or server object this is attached to
  /// @param isServer True if this is the server, false otherwise
  /// @param portNum The port for this server (ignored if isServer is false)
  /// @param maxConns The maximum number of connections for this server (ignored if isServer is false)
  NetPeer::NetPeer(Game* parent, bool isServer, unsigned short portNum, unsigned int maxConns)
  {
  
    _parent = parent;
    _isServer = isServer;
    // Construct our objects
    // Our connection factory is responsible for making objects in the replica manager
    _connFactory = new ReplicaObjectConstructorFactory(_parent->GetGameState());
    // The replica manager is responsible for handling replica packets
    _repMngr = new RakNet::ReplicaManager2();
    _repMngr->SetDefaultPacketReliability(PacketReliability::UNRELIABLE_SEQUENCED);
    // Manages network ids of objects we create
    _netIDMngr = new NetworkIDManager();

#if _DEBUG
    // For now, we only log all the packets in debug mode
    _log = new PacketFileLogger();
#endif

    // Set up our peer (the raknet object responsible for connections)
    _peer = RakNetworkFactory::GetRakPeerInterface();
    _peer->SetNetworkIDManager(_netIDMngr);

    
    // Establish whether this peer has the rights to create and destroy objects
    _netIDMngr->SetIsNetworkIDAuthority(isServer);
    
    // attach our plugins
    _peer->AttachPlugin(_repMngr);

#if _DEBUG
    _peer->AttachPlugin(_log);

    // Start our log
    _log->SetPrintAcks(false);    
    if (_isServer)
    {
    _log->StartLog("serverLog");
    }
    else
    {
      _log->StartLog("clientLog");
    }
#endif

    // Set up our connection factory for replica manager
    _repMngr->SetConnectionFactory(_connFactory);

    // Set up the server or client's ip/port/max connections
    if(isServer)
    { // Set up the server
		  SocketDescriptor s(portNum, 0);
		  // Start the server
      _peer->Startup(maxConns, PEER_HEARTBEAT_DELAY, &s, 1);
      // Set the maximum connections allowed by the server
      _peer->SetMaximumIncomingConnections(maxConns);
      // Automatically add new connections to the replica manager system
      _repMngr->SetAutoAddNewConnections(true);
    }
    else
    { // Set up the client
		  SocketDescriptor s;
      _peer->Startup(1, PEER_HEARTBEAT_DELAY, &s, 1);
    }

    #if _DEBUG
    // Report to the console if we are debugging.
    if (isServer)
    {
      std::cout << "NetPeer (server) finished construction." << std::endl;
    }    
    else
    {
      std::cout << "NetPeer (client) finished construction." << std::endl;
    }
    #endif
  }


  NetPeer::~NetPeer()
  {
    #if _DEBUG
    // Report to the console if debugging
    if (_isServer)
    {
      std::cout << "NetPeer (server) shutting down." << std::endl;
    }    
    else
    {
      std::cout << "NetPeer (client) shutting down." << std::endl;
    }
    #endif
    // Shut down our client/server, waiting PEER_SHUTDOWN_DELAY ms for any packets to send
    _peer->Shutdown(PEER_SHUTDOWN_DELAY);
    // We're shutdown, clean up the peer
    RakNetworkFactory::DestroyRakPeerInterface(_peer);
  }

  // When we receive a packet, it stays in the queue of received packets
  // until we Deallocate it. This is an important step.
  void NetPeer::DeallocatePacket(Packet* packet)
  {
    // pass the packet to the raknet peer.
    _peer->DeallocatePacket(packet);
  }

  // Returns the packet in the front of the arrived packets queue, but does
  // not remove it from the queue. It is important to call Deallocate
  // on the packet after you are done with it.
  Packet* NetPeer::Receive()
  {
    return _peer->Receive();
  }

  // Connects this peer to another peer. Returns false if this peer is a server.
  // Also returns false if there was something wrong with the client setup.
  // Note: This cannot be used to detect whether the client successfully connected
  // to the server, just whether the client was set up properly to make the attempt.
  bool NetPeer::Connect(const char* host,unsigned short remotePort, const char* passwordData,int pwdDataLength)
  {
    if (!_isServer)
    {
      return _peer->Connect(host, remotePort,passwordData, pwdDataLength);
    }
    return false;
  }

  SystemAddress NetPeer::GetLocalAddress()
  {
    return _peer->GetExternalID(UNASSIGNED_SYSTEM_ADDRESS);
  }
}