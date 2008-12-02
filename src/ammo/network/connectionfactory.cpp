#include "ammo/network/connectionfactory.hpp"
#include "ammo/game/gameobjects/sampleobject.hpp"

#include <iostream>

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
    int objType;
    replicaData->Read(objType);

    if (objType == 1)
    {
      std::cout << "Connection Factory creating new Sample Object" << std::endl;
      construct = new SampleObject();
    }
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