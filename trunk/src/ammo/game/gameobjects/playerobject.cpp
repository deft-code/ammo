#include "ammo/game/gameobjects/playerobject.hpp"

#include "ammo/enums/gameobjects.hpp"
#include <iostream>

using std::cout;
using std::endl;

namespace ammo
{

  // Update contains all the logic for the object. 
  void PlayerObject::Update(float deltaTime)
  {
    // Update our sprite's information 
    _sprite.SetPosition(_physic.GetPosition());
    
  }
  // Serializes the player. If the player is on the client, it serializes only the input information,
  // if the player is on the server, it serializes the the players state.
  bool PlayerObject::Serialize(RakNet::BitStream* bitStream, RakNet::SerializationContext* serializationContext)
  {
    if (_parent->GetGameState()->GetIsAuthority())
    {
      // We are the server! Squigglydurn!
      return SerializeServerSide(bitStream, serializationContext);
    }
    else
    {
      // We are the client! Clunkerypiggle!
      return SerializeClientSide(bitStream, serializationContext);
    }    
  }

  // Serializes the construction of the player. This is deserialized by the ReplicaObjectConstructor.Construct 
  // method(see: connectionFactory.h). Currently serializes only the object type.
  bool PlayerObject::SerializeConstruction(RakNet::BitStream* bitStream, RakNet::SerializationContext* serializationContext)
  {
    // Write our type to the bit stream
    bitStream->Write((int)ammo::enums::PLAYER_OBJECT);        
    return true;
  }

  // Deserializes the data sent via the Serialize Method
  void PlayerObject::Deserialize(RakNet::BitStream* bitStream, RakNet::SerializationType serializationType, SystemAddress sender, RakNetTime timestamp)
  {
    if (_parent->GetGameState()->GetIsAuthority())
    {
      // We are the server! Squigglydurn!
      DeserializeServerSide(bitStream, serializationType, sender, timestamp);
    }
    else
    {
      // We are the client! Clunkerypiggle!
      DeserializeClientSide(bitStream, serializationType, sender, timestamp);
    }  
  }
  // After the object is completely registered on client/server, this method is called to load up any graphics, or do any post constructor
  // initialization.
  void PlayerObject::OnRegisterComplete()
  {
    // Get our sprite
    _sprite = _parent->GetGraphicSys()->getGraphic("player");
    _sprite.show();

    // Get our sound
    _sound = _parent->GetSoundSys()->getSound("player");
    
    // Point our local gamestate's camera at us
    if (!_parent->GetGameState()->GetIsAuthority())
    {
      // But only if this is a client. 
      _parent->SetCameraTarget((ICameraTarget*)(&_sprite));
    }
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