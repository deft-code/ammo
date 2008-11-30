#include "ammo/network/connectionfactory.hpp"

namespace ammo
{
  // Constructs our factory, storing the gamestate to register
  // any objects to.
  ReplicaObjectConstructor::ReplicaObjectConstructor(ammo::GameState *gameState)
  {
    _gameState = gameState;
  }
  // Constructs a game object
  RakNet::Replica2* ReplicaObjectConstructor::Construct(RakNet::BitStream *replicaData, SystemAddress sender, RakNet::SerializationType type, RakNet::ReplicaManager2 *replicaManager, RakNetTime timestamp, NetworkID networkId, bool networkIDCollision)
  {
    GameObject* construct = NULL;
    // Determine which object we need to construct, based on the bitstream

    // Create an instance of that object

    // After we construct the object, we need to register that object 
    // with the gamestate. 
    if (construct && _gameState)
    { 
      _gameState->RegisterGameObject(construct);
    }

    return construct;
  }
    
}