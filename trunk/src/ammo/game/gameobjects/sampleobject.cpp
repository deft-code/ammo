#include "ammo/game/gameobjects/sampleobject.hpp"

#include <iostream>

namespace ammo
{
    void SampleObject::Update(float deltaTime)
    {
      
      _timer -= deltaTime;
      if(_parent->GetGameState()->GetIsAuthority())
      {
        // On the server, 
        if (_timer <= 0)
        {
          _timer += 2;
          _myVal++;
        }        
      }
      else
      {
        _sprite.SetX(0 + _myVal);
        if  (_myVal % 5 == 0)
        {
          _sound.play();
        }
      }
    }

    bool SampleObject::Serialize(RakNet::BitStream* bitStream, RakNet::SerializationContext* serializationContext)
    {
      std::cout << "Server Serialized _myVal. Value: " << _myVal << std::endl;
      (*bitStream) << _myVal;
      return true;
    }

    bool SampleObject::SerializeConstruction(RakNet::BitStream* bitStream, RakNet::SerializationContext* serializationContext)
    {
      int objNum = 1;
      bitStream->Write(objNum);     
      return true;
    }

    void SampleObject::Deserialize(RakNet::BitStream* bitStream, RakNet::SerializationType serializationType, SystemAddress sender, RakNetTime timestamp)
    {
      (*bitStream) >> _myVal;
      std::cout << "Client Deserialized value: " << _myVal << std::endl;
    }

    void SampleObject::OnRegisterComplete()
    {
      _sprite = _parent->GetGraphicSys()->getGraphic("player");
      _sprite.SetPosition(b2Vec2(300, 300));
      _sprite.show();

      // If we are the client, load up the sound
      if (!_parent->GetGameState()->GetIsAuthority())
      {
        _sound = _parent->GetSoundSys()->getSound("player");
        
      }
    }
}