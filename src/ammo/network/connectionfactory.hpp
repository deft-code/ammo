#ifndef CONNFACTORY_H_INCLUDED
#define CONNFACTORY_H_INCLUDED

#include "ReplicaManager2.h"
#include "ammo/game/gamestate.hpp"

namespace ammo
{
  class GameState;
  // This object is responsible for creating all of our game objects
  // on the client side when the server tells the client to construct
  // an object
  class ReplicaObjectConstructor : public RakNet::Connection_RM2
  {
  public:
    ReplicaObjectConstructor(GameState* gameState);
    // Callback to construct objects
    RakNet::Replica2* Construct(RakNet::BitStream* replicaData, SystemAddress sender, RakNet::SerializationType type,
      RakNet::ReplicaManager2* replicaManager, RakNetTime timestamp, NetworkID networkId, bool networkIDCollision);
  private:
    GameState* _gameState;
  };


  // Raknet allows us to use different object factories on each peer, which means
  // there must be a factory factory. Because we are only using one type of Object
  // Factory, this is kinda redundant, but this class is here to make the interfaces
  // all work out.
  class ReplicaObjectConstructorFactory : public RakNet::Connection_RM2Factory
  {
  public:
    // gameState - The gamestate that should register the objects the 
    // product of this factory creates.
    ReplicaObjectConstructorFactory(GameState* gameState) { _gameState = gameState;}
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