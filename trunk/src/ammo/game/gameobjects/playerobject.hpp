#ifndef PLAYER_OBJECT_HPP
#define PLAYER_OBJECT_HPP

#include "ammo/game/gameobject.hpp"
#include "ammo/graphics.hpp"
#include "ammo/audio.hpp"
#include "ammo/physics.hpp"

#include "RakNetTypes.h"

namespace ammo
{
  class PlayerObject : public GameObject
  {
  public:
    // Constructor
    PlayerObject() { };

    // Update contains all the logic for the object. 
    void Update(float deltaTime);    
    // Serializes the player. If the player is on the client, it serializes only the input information,
    // if the player is on the server, it serializes the the players state.
    bool Serialize(RakNet::BitStream* bitStream, RakNet::SerializationContext* serializationContext);
    // Serializes the construction of the player. This is deserialized by the ReplicaObjectConstructor.Construct 
    // method(see: connectionFactory.h). Currently serializes only the object type.
    bool SerializeConstruction(RakNet::BitStream* bitStream, RakNet::SerializationContext* serializationContext);
    // Deserializes the data sent via the Serialize Method
    void Deserialize(RakNet::BitStream* bitStream, RakNet::SerializationType serializationType, SystemAddress sender, RakNetTime timestamp);
    // After the object is completely registered on client/server, this method is called to load up any graphics, or do any post constructor
    // initialization.
    void OnRegisterComplete();
  private:
    // Handles serializing all of our information on the client side
    bool SerializeClientSide(RakNet::BitStream* bitStream, RakNet::SerializationContext* serializationContext);
    // Handles serializing all of our information on the server side
    bool SerializeServerSide(RakNet::BitStream* bitStream, RakNet::SerializationContext* serializationContext);

    // Handles deserializing all of our information on the client side, from the data received sent via SerializeServerSide
    bool DeserializeClientSide(RakNet::BitStream* bitStream, RakNet::SerializationType serializationType, SystemAddress sender, RakNetTime timestamp);
    // Handles deserializing all of our information on the server side, from the data received sent via SerializeClientSide
    bool DeserializeServerSide(RakNet::BitStream* bitStream, RakNet::SerializationType serializationType, SystemAddress sender, RakNetTime timestamp);
    
    // Our tokens

    // Our player sprite, currently only one per player
    ammo::Graphic _sprite;
    // Our player sound token
    ammo::Sound _sound;
    // Our physics token
    ammo::Physic _physic;
  };
}

#endif // PLAYER_OBJECT_HPP