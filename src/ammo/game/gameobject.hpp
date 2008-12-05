#ifndef GAME_OBJECT_H_INCLUDED
#define GAME_OBJECT_H_INCLUDED

#include "ReplicaManager2.h"
#include "ammo/game/game.hpp"

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
    GameObject() { _parent = NULL; }
    void SetParentGame(Game* parent) { _parent= parent;}
    // This method is called when the object has been registered with the system, and has all
    // it's pointers set up. This is where you should get your graphics tokens from the 
    // graphic system.
    virtual void OnRegisterComplete() = 0;
    virtual void Update(float deltaTime) =0;
  protected:
    Game* _parent;
  };
}

#endif  // Game Object H Included