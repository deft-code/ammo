#ifndef SAMPLE_OBJECT_H
#define SAMPLE_OBJECT_H

#include "ammo/game/gameobject.hpp"
#include "ammo/graphics.hpp"
#include "ammo/audio.hpp"
#include "ammo/enums/gameobjects.hpp"

#include "RakNetTypes.h"

namespace ammo
{
  // The sample object is an example of how to implement
  // a Game Object. This object has no 
  class SampleObject : public GameObject
  {
  public:
    SampleObject()
	  : _myVal(0),
		 _timer(2)
	 {	}

    // Update contains all the logic for the object. 
    void Update(float deltaTime);    
    // Puts data into the bitstream. This is called automatically by Raknet. Put in all the information you need
    // to be sent on serialization
    bool Serialize(RakNet::BitStream* bitStream, RakNet::SerializationContext* serializationContext);
    // Puts data into the bitstream. This is called when the object is first created, Raknet is expecting you to serialize an indicator
    // of which object type you are serializing first, then any data for that object.
    bool SerializeConstruction(RakNet::BitStream* bitStream, RakNet::SerializationContext* serializationContext);
    // Deserializes the data sent via the Serialize Method
    void Deserialize(RakNet::BitStream* bitStream, RakNet::SerializationType serializationType, SystemAddress sender, RakNetTime timestamp);
    // After the object is completely registered on client/server, this method is called to load up any graphics, or do any post constructor
    // initialization.
    void OnRegisterComplete();

    int type() const { return enums::SAMPLE_OBJECT; }

  private:
    // Logic variables
    int _myVal;
    float _timer;
    // Graphics token
    ammo::Graphic _sprite;
    // Sound token
    ammo::Sound _sound;
  };
}
#endif // SAMPLE_OBJECT_H

