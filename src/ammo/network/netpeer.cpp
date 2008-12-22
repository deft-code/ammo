#include "ammo/network/netpeer.hpp"

#include <iostream>

namespace ammo
{

  NetPeer::NetPeer(Game* parent, bool isServer, unsigned short portNum, unsigned int maxConns)
  {
    _parent = parent;
    _isServer = isServer;
    
    // Construct our objects
    _connFactory = new ReplicaObjectConstructorFactory(_parent->GetGameState());
    _repMngr = new RakNet::ReplicaManager2();
    _netIDMngr = new NetworkIDManager();

#if _DEBUG
    _log = new PacketFileLogger();
#endif

    // Set up our peer
    _peer = RakNetworkFactory::GetRakPeerInterface();
    _peer->SetNetworkIDManager(_netIDMngr);

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

    _repMngr->SetConnectionFactory(_connFactory);
    // Hardcoded client/server setup for now
    if(isServer)
    { // Set up the server
		 SocketDescriptor s(portNum, 0);
      _peer->Startup(maxConns, 30, &s, 1);
      _peer->SetMaximumIncomingConnections(maxConns);
      _repMngr->SetAutoAddNewConnections(true);
    }
    else
    { // Set up the client
		 SocketDescriptor s;
      _peer->Startup(1, 30, &s, 1);
    }

    #if _DEBUG
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
    if (_isServer)
    {
      std::cout << "NetPeer (server) shutting down." << std::endl;
    }    
    else
    {
      std::cout << "NetPeer (client) shutting down." << std::endl;
    }
    #endif
    
    _peer->Shutdown(100);
    RakNetworkFactory::DestroyRakPeerInterface(_peer);
  }

  void NetPeer::DeallocatePacket(Packet* packet)
  {
    _peer->DeallocatePacket(packet);
  }

  Packet* NetPeer::Receive()
  {
    return _peer->Receive();
  }

  // Connects this peer to another peer. Ignored if this peer is a server.
  bool NetPeer::Connect(const char* host,unsigned short remotePort, const char* passwordData,int pwdDataLength)
  {
    if (!_isServer)
    {
      return _peer->Connect(host, remotePort,passwordData, pwdDataLength);
    }
    return false;
  }
}