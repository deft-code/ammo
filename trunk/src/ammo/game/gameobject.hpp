#ifndef GAME_OBJECT_H_INCLUDED
#define GAME_OBJECT_H_INCLUDED

#include "ReplicaManager2.h"
#include "ammo/game/gamestate.hpp"

namespace ammo
{
  class GameState;
  using RakNet::Replica2;
  // The base class for every serializable object.
  // After this object is constructed, make sure to
  // call GameState.RegisterGameObject to ensure
  // it is properly registered with the game state
  // and the network.
  class GameObject : public Replica2
  {
  public:   
    GameObject() { _parentState = NULL; }
    void SetParentGameState(GameState* parent) { _parentState = parent;}
    virtual void Update(float deltaTime) =0;
  protected:
    GameState* _parentState;
  };
}

#endif  // Game Object H Included