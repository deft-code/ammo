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
    if(_parent)
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

    return true;
  }

  // Serializes the construction of the player. This is deserialized by the ReplicaObjectConstructor.Construct 
  // method(see: connectionFactory.h). Currently serializes only the object type.
  bool PlayerObject::SerializeConstruction(RakNet::BitStream* bitStream, RakNet::SerializationContext* serializationContext)
  {
    // Write our type to the bit stream
    bitStream->Write((int)ammo::enums::PLAYER_OBJECT);  
    bitStream->Write(_owner);
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
    _sprite.SetSize(b2Vec2(9.8,25.6));
    _sprite.show();

    // Get our sound
    _sound = _parent->GetSoundSys()->getSound("player");
    
    // Get our 'physic'
    _physic = _parent->GetPhysicsSys()->GetPhysic("player");
    _physic.SetPosition(b2Vec2(0, 0));
    // Give the player some initial velocity
    _physic.SetVelocity(b2Vec2(0, 10));
    // Point our local gamestate's camera at us
    if (!_parent->GetGameState()->GetIsAuthority() && _parent->GetNetPeer()->GetLocalAddress() == _owner)
    {
      // But only if this is a client, and this is our player
      _parent->SetCameraTarget((ICameraTarget*)(&_physic));
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
    bitStream->Write(_physic.GetPosition());
    return true;
  }

  // Handles deserializing all of our information on the client side, from the data received sent via SerializeServerSide
  bool PlayerObject::DeserializeClientSide(RakNet::BitStream* bitStream, RakNet::SerializationType serializationType, SystemAddress sender, RakNetTime timestamp)
  {
    b2Vec2 temp;
    bitStream->Read(temp);
    _physic.SetPosition(temp);
    return true;
  }

  // Handles deserializing all of our information on the server side, from the data received sent via SerializeClientSide
  bool PlayerObject::DeserializeServerSide(RakNet::BitStream* bitStream, RakNet::SerializationType serializationType, SystemAddress sender, RakNetTime timestamp)
  {

    return true;
  }

  bool PlayerObject::QueryIsSerializationAuthority() const
  {   
    // If we are the server, or we are the owner of this object, allow us to serialize it
    if(_parent->GetNetPeer()->GetLocalAddress() == _owner || _parent->GetGameState()->GetIsAuthority())
    {
      return true;
    }
    else
    {
      return false;
    }
  }
}