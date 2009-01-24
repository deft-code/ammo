#include "ammo/game/gameobjects/playerobject.hpp"

#include <iostream>

namespace ammo
{

  // Update contains all the logic for the object. 
  void PlayerObject::Update(float deltaTime)
  {

  }
  // Serializes the player. If the player is on the client, it serializes only the input information,
  // if the player is on the server, it serializes the the players state.
  bool PlayerObject::Serialize(RakNet::BitStream* bitStream, RakNet::SerializationContext* serializationContext)
  {
    return true;
  }

  // Serializes the construction of the player. This is deserialized by the ReplicaObjectConstructor.Construct 
  // method(see: connectionFactory.h). Currently serializes only the object type.
  bool PlayerObject::SerializeConstruction(RakNet::BitStream* bitStream, RakNet::SerializationContext* serializationContext)
  {
    return true;
  }
  // Deserializes the data sent via the Serialize Method
  void PlayerObject::Deserialize(RakNet::BitStream* bitStream, RakNet::SerializationType serializationType, SystemAddress sender, RakNetTime timestamp)
  {

  }
  // After the object is completely registered on client/server, this method is called to load up any graphics, or do any post constructor
  // initialization.
  void PlayerObject::OnRegisterComplete()
  {

  }

  // Handles serializing all of our information on the client side
  bool PlayerObject::SerializeClientSide(RakNet::BitStream* bitStream, RakNet::SerializationContext* serializationContext)
  {
    return true;
  }
  // Handles serializing all of our information on the server side
  bool PlayerObject::SerializeServerSide(RakNet::BitStream* bitStream, RakNet::SerializationContext* serializationContext)
  {
    return true;
  }

  // Handles deserializing all of our information on the client side, from the data received sent via SerializeServerSide
  bool PlayerObject::DeserializeClientSide(RakNet::BitStream* bitStream, RakNet::SerializationType serializationType, SystemAddress sender, RakNetTime timestamp)
  {
    return true;
  }

  // Handles deserializing all of our information on the server side, from the data received sent via SerializeClientSide
  bool PlayerObject::DeserializeServerSide(RakNet::BitStream* bitStream, RakNet::SerializationType serializationType, SystemAddress sender, RakNetTime timestamp)
  {
    return true;
  }
}