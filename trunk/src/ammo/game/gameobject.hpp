#ifndef GAME_OBJECT_H_INCLUDED
#define GAME_OBJECT_H_INCLUDED

#include "ReplicaManager2.h"
#include "ammo/game/game.hpp"

/* 

HOW TO MAKE A GAME OBJECT IN THREE EASY STEPS

1.) Create a new object, and inherit from GameObject

2.) Implement:
Update() -- What your object does
Serialize() -- How your object packs itself for the net
Deserialize() -- How your object unpacks itself from a packet
SerializeConstruction() -- How this object indicates to the factory on the client
   that it needs to be constructed. (You can use a simple string for this.) As well
   as any necessary construction parameters.

3.) Add code to actually construct an instance of the object in 
   ReplicaObjectConstructor::Construct()

   Making sure to fill in only:
   // Determine which object we need to construct, based on the bitstream

   // Create an instance of that object

The factory will register the constructed object everywhere it needs to be registered
by calling _gameState->RegisterGameObject, and everything else is handled for you.

You can optionally call AddAutoSerializeTimer() to change the default
serialization time.

There are a number of callbacks you can also implement that are optional for limiting
when the object is serialized, how it is serialized, etc. See: 
http://www.jenkinssoftware.com/raknet/manual/Doxygen/html/classRakNet_1_1Replica2.html
*/

namespace ammo
{
  class Game;
  using RakNet::Replica2;
  // The base class for every serializable object.
  // After this object is constructed, make sure to
  // call GameState.RegisterGameObject to ensure
  // it is properly registered with the game state
  // and the network.
  class GameObject : public Replica2
  {
  public:   
    GameObject()
     : _parent(NULL)
    { }

    virtual ~GameObject() { }

    void SetParentGame(Game* parent) { _parent= parent;}
    // This method is called when the object has been registered with the system, and has all
    // it's pointers set up. This is where you should get your graphics tokens from the 
    // graphic system.
    virtual void OnRegisterComplete() = 0;
    virtual void Update(float deltaTime) =0;
    virtual void DeserializeDestruction(RakNet::BitStream * bitStream, 
      RakNet::SerializationType serializationType, SystemAddress sender, RakNetTime timestamp);

	  virtual int type() const =0;
  protected:
    Game* _parent;
  };
}

#endif  // Game Object H Included
