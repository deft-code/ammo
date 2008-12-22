#ifndef CONNFACTORY_H_INCLUDED
#define CONNFACTORY_H_INCLUDED

#include "ReplicaManager2.h"
#include "ammo/game/gamestate.hpp"

namespace ammo
{
  class GameState;
  // This object is responsible for creating all of our game objects
  // on the client side when the server tells the client to construct
  // an object. 
  class ReplicaObjectConstructor : public RakNet::Connection_RM2
  {
  public:
    ReplicaObjectConstructor(GameState* gameState);
    // Callback to construct objects. This should not be called directly.
    // The replica2manager object will hand a packet to this method, and expect
    // to receive a constructed object based on the contents of the packet.
    // @param replicaData The byte array that was sent from the server when the object was serialized
    // @param sender The address of the server that sent this object
    // @param type The serializationType, you will generally not need to use this
    // @param replicaManager The local replicaManager, should it be needed
    // @param timestamp The time that was sent with this packet in the serializeconstruction method on the server
    // @param networkId The networkId that will be assigned to this object
    // @param networkIdCollision True if the networkid that should be assigned is already in use locally
    RakNet::Replica2* Construct(RakNet::BitStream* replicaData, SystemAddress sender, RakNet::SerializationType type,
      RakNet::ReplicaManager2* replicaManager, RakNetTime timestamp, NetworkID networkId, bool networkIDCollision);
  private:
    GameState* _gameState;
  };


  // Raknet allows us to use different object factories on each peer, which means
  // there must be a factory factory. Because we are only using one type of Object
  // Factory, this is kinda redundant, but we have to implement this.
  class ReplicaObjectConstructorFactory : public RakNet::Connection_RM2Factory
  {
  public:
    // gameState - The gamestate that should register the objects the 
    // product of this factory creates.
    ReplicaObjectConstructorFactory(GameState* gameState) { _gameState = gameState;}
    // We only have one factory, so this method will always return that one object
    virtual RakNet::Connection_RM2* AllocConnection(void) const
    {
      return new ReplicaObjectConstructor(_gameState);
    }
    virtual void DeallocConnection(RakNet::Connection_RM2* s) const
    {
      delete s;
    }
  private:
    GameState* _gameState;
  };
}

#endif // CONNFACTORY_H_INCLUDED