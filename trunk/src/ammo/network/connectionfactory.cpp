#include "ammo/network/connectionfactory.hpp"
// TODO
// Pull out the object headers to  ammo/game/gameobjects/gameobjects.hpp
// or something
#include "ammo/game/gameobjects/sampleobject.hpp"
#include "ammo/game/gameobjects/playerobject.hpp"

#include "ammo/enums/gameobjects.hpp"

#include <iostream>

namespace ammo
{    
  // Constructs our factory, storing the gamestate to register
  // any objects to.
  ReplicaObjectConstructor::ReplicaObjectConstructor(ammo::GameState *gameState)
  {
    _gameState = gameState;
  }
  
  // Constructs a game object based on a packet from the replica manager.
  // Never call this directly.
  RakNet::Replica2* ReplicaObjectConstructor::Construct(RakNet::BitStream *replicaData, SystemAddress sender, RakNet::SerializationType type, RakNet::ReplicaManager2 *replicaManager, RakNetTime timestamp, NetworkID networkId, bool networkIDCollision)
  {
    // The object we may (or may not) be creating. Initally NULL
    GameObject* construct = NULL;
    // Determine which object we need to construct, based on the bitstream
    int objType;
    // Read out one int from the front of the bitstream
    replicaData->Read(objType);

    // Respond to the type of the object
    // TODO: We need to establish a standard for enumerating these
    switch (objType)
    { 
	 case enums::PLAYER_OBJECT:
      {
        SystemAddress myOwner;
        replicaData->Read(myOwner);
        std::cout << "Connection Factory creating new Player Object from " << sender.ToString() << ". Owner is " << myOwner.ToString() << std::endl;
        construct = new PlayerObject(myOwner);
        construct->AddAutoSerializeTimer(0);
        break;
      }
    case enums::SAMPLE_OBJECT:
        std::cout << "Connection Factory creating new Sample Object" << std::endl;
        construct = new SampleObject();
        break;
    default:
        break;
    }

    // After we construct the object, we need to register that object 
    // with the gamestate. 
    if (construct && _gameState)
    {  // If we constructed the object, and we have a valid gamestate pointer
      // Register the object, which will make the local gamestate aware of the object.
      _gameState->RegisterGameObject(construct);
    }

    // return the object we made (or null)
    return construct;
  }   
}