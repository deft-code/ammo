#include "ammo/game/gamestate.hpp"


namespace ammo
{
  GameState::GameState(ammo::Game *parent)
  {
    _parent = parent;
  }

  void GameState::RegisterGameObject(ammo::GameObject *object)
  {
    if (object)
    {
      // Register this object internally
      _objList.push_back(object);

      // Register this object for the net
      // if it hasn't been registered there already
      if (!object->GetReplicaManager())
      {
        // Set the replica manager for the object, which should be 
        // enough to get our object serializing properly.
        object->SetReplicaManager(_parent->GetNetPeer()->GetRepMngr());
      }

      // Set our parent
      object->SetParentGame(_parent);

      // If this is the server, we need to broadcast the construction of the object
      if (this->_parent->GetGameState()->GetIsAuthority())
      {
        object->BroadcastConstruction();
      }

      // Finish up any post serialization initialization
      object->OnRegisterComplete();
    }
  }

  void GameState::UnregisterGameObject(ammo::GameObject *object)
  {
    if (object)
    {
      _objList.remove(object);

      if (_parent->GetGameState()->GetIsAuthority())
      {
        object->BroadcastDestruction();        
      }
    }
  }

  void GameState::SetTarget(ICameraTarget* target)
  { 
    _parent->SetCameraTarget(target); 
  }
}
