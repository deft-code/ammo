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
      object->SetParentGameState(this);
      if (this->_parent->GetGameState()->GetIsAuthority())
      {
        object->BroadcastConstruction();
      }
    }
  }
}