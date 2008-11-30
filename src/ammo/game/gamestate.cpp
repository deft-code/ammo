#include "ammo/game/gamestate.hpp"


namespace ammo
{

  void GameState::RegisterGameObject(ammo::GameObject *object)
  {
    if (object)
    {
      // Register this object internally
      // TODO

      // Register this object for the net
      // if it hasn't been registered there already
      if (!object->GetReplicaManager())
      {
        // Set the replica manager for the object, which should be 
        // enough to get our object serializing properly.
        object->SetReplicaManager(_parent->GetNetPeer()->GetRepMngr());
      }
    }
  }
}