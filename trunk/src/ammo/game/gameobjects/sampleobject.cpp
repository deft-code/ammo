#include "ammo/game/gameobjects/sampleobject.hpp"

#include <iostream>

namespace ammo
{
    void SampleObject::Update(float deltaTime)
    {
      _timer -= deltaTime;
      if (_timer <= 0)
      {
        _timer += 2;
        _myVal++;
        if (this->_parentState->GetIsAuthority())
        {
          std::cout << "Server Incremented _myVal" << std::endl;
        }
        else
        {
          std::cout << "Client Incremented _myVal" << std::endl;
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

}