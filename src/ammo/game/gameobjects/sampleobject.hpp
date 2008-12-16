#ifndef SAMPLE_OBJECT_H
#define SAMPLE_OBJECT_H

#include "ammo/game/gameobject.hpp"
#include "ammo/graphics.hpp"
#include "ammo/audio.hpp"

#include "RakNetTypes.h"

namespace ammo
{
  // The sample object is an example of how to implement
  // a Game Object. This object 
  class SampleObject : public GameObject
  {
  public:
    SampleObject()
	  : _myVal(0),
		 _timer(2)
	 {	}

    void Update(float deltaTime);    
    bool Serialize(RakNet::BitStream* bitStream, RakNet::SerializationContext* serializationContext);
    bool SerializeConstruction(RakNet::BitStream* bitStream, RakNet::SerializationContext* serializationContext);
    void Deserialize(RakNet::BitStream* bitStream, RakNet::SerializationType serializationType, SystemAddress sender, RakNetTime timestamp);
    void OnRegisterComplete();
  private:
    int _myVal;
    float _timer;
    ammo::Graphic _sprite;
    ammo::Sound _sound;
  };
}
#endif // SAMPLE_OBJECT_H