#include "ammo/game/gameobjects/playerobject.hpp"

#include "ammo/enums/gameobjects.hpp"
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

namespace ammo
{
  // Update contains all the logic for the object. 
  void PlayerObject::Update(float deltaTime)
  {
    
    // Handle our input
    if (_input.GetValue(ammo::enums::LEFT) > 0.0f)
    {
      _physic.SetTheta(_physic.GetTheta() + TURN_RATE);
    }
    if (_input.GetValue(ammo::enums::RIGHT) > 0.0f)
    {
      _physic.SetTheta(_physic.GetTheta() - TURN_RATE);
    }
    if (_input.GetValue(ammo::enums::THRUST) > 0.0f )
    {
      float theta = _physic.GetTheta();
      float thrust = THRUST_RATE;
      if (_input.GetValue(ammo::enums::AFTERBURN) > 0.0f)
      {
        thrust *= BURN_MULTIPLIER;
      }
      _physic.SetVelocity(_physic.GetVelocity() + thrust * (b2Vec2((float)cos(theta), (float)sin(theta))));
    }    
    if (_input.GetValue(ammo::enums::REVERSE) > 0.0f )
    {
      float theta = _physic.GetTheta();
      _physic.SetVelocity(_physic.GetVelocity() - THRUST_RATE * (b2Vec2((float)cos(theta), (float)sin(theta))));
    }

    // Cap our velocity
    if (_physic.GetVelocity().LengthSquared() > MAX_SPEED_SQUARED)
    {
      _physic.GetVelocity().Normalize();
      _physic.SetVelocity(MAX_SPEED * _physic.GetVelocity());
    }

    // Update our sprite's information 
    _sprite.SetPosition(_physic.GetPosition());     
    _sprite.SetRotationRadians(_physic.GetTheta());
    
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
    _sprite.SetSize(b2Vec2(9.8f,25.6f));        
    
    _sprite.show();

    // Get our sound
    _sound = _parent->GetSoundSys()->getSound("player");
    
    // Get our 'physic'
    _physic = _parent->GetPhysicsSys()->GetPhysic("player", *this);
    //_physic.SetPosition(b2Vec2(0.0f, 0.0f));
    // Give the player some initial velocity
    _physic.SetVelocity(b2Vec2(0.0f, 0.0f));
    // And some initial rotation, for fun
    _physic.SetOmega(0.0f);

    _input = _parent->GetInputSys()->GetInput("player");
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
    // Where the input is serialized, but we don't that at all because someone is a terrible human being.
    for (int i = 0; i < PLAYER_ACTIONS_COUNT; i++)
    {
      bitStream->Write(_input.GetValue((ammo::enums::enumPlayerAction)i));
    }
    return true;
  }
  // Handles serializing all of our information on the server side
  bool PlayerObject::SerializeServerSide(RakNet::BitStream* bitStream, RakNet::SerializationContext* serializationContext)
  {    
    bitStream->Write(_physic.GetPosition());
    bitStream->Write(_physic.GetTheta());
    bitStream->Write(_physic.GetOmega());
    return true;
  }

  // Handles deserializing all of our information on the client side, from the data received sent via SerializeServerSide
  bool PlayerObject::DeserializeClientSide(RakNet::BitStream* bitStream, RakNet::SerializationType serializationType, SystemAddress sender, RakNetTime timestamp)
  {
    b2Vec2 temp;
    float ftemp;
    bitStream->Read(temp);
    bitStream->Read(ftemp);
    _physic.SetPosition(temp);
    _physic.SetTheta(ftemp);
    (*bitStream) >> ftemp;
    _physic.SetOmega(ftemp);

    return true;
  }

  // Handles deserializing all of our information on the server side, from the data received sent via SerializeClientSide
  bool PlayerObject::DeserializeServerSide(RakNet::BitStream* bitStream, RakNet::SerializationType serializationType, SystemAddress sender, RakNetTime timestamp)
  {
    float buffer; 
    for (int i = 0; i < PLAYER_ACTIONS_COUNT; i++)
    {
      (*bitStream) >> buffer;
      _input.SetValue((ammo::enums::enumPlayerAction)i, buffer);
    }

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