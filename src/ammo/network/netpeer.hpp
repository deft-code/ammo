#ifndef NET_PEER_H_INCLUDED
#define NET_PEER_H_INCLUDED

// Projet Includes
#include "ammo/game/game.hpp"
#include "ammo/network/connectionfactory.hpp"

// RakNet Includes
#include "RakPeerInterface.h"
#include "NetworkIDManager.h"
#include "RakNetworkFactory.h"
#include "BitStream.h"
#include "ReplicaManager2.h"
#include "RakNetTypes.h"

using RakNet::ReplicaManager2;
namespace ammo
{

  class Game;
  class ReplicaObjectConstructorFactory;

  // Net Peer is the class responsbile for handling all the network transactions between 
  // a client and a server. It can be a member of a client or a server
  class NetPeer
  {
  public:
    NetPeer(Game* parent, bool isServer);
    ~NetPeer();
    // Receive a waiting packet from the net peer
    // Make sure to call DeallocatePacket on the 
    // packet you receive, or the packet will not
    // leave the queue
    Packet* Receive();
    // Removes the packet from the queue once you 
    // have received it.
    void DeallocatePacket(Packet* packet);
    // Gets the replica manager. Objects intending to use
    // the replica system need to call SetReplicaManager
    // and pass in this pointer.
    RakNet::ReplicaManager2* GetRepMngr() {return _repMngr;};
  private:
    // Our RakNet peer (the object that actually manages the connection)
    RakPeerInterface* _peer;
    // Our RakNet NetworkIdManager
    NetworkIDManager* _netIDMngr;
    // The object responsible for managing our replications
    ReplicaManager2*  _repMngr;
    // The object factory factory
    ReplicaObjectConstructorFactory* _connFactory;
    // Our parent class
    Game* _parent;
    // Whether this peer is acting as a client or a server
    bool _isServer;
  };
}
#endif // NET_PEER_H_INCLUDED