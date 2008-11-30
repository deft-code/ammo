#ifndef GAME_OBJECT_H_INCLUDED
#define GAME_OBJECT_H_INCLUDED

#include "ReplicaManager2.h"

namespace ammo
{
  using RakNet::Replica2;
  // The base class for every serializable object.
  // After this object is constructed, make sure to
  // call GameState.RegisterGameObject to ensure
  // it is properly registered with the game state
  // and the network.
  class GameObject : public Replica2
  {
  public:   
    
  private:
    
  };
}

#endif  // Game Object H Included