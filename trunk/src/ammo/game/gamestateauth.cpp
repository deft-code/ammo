#include "ammo/game/gamestateauth.hpp"

namespace ammo
{
  AuthGameState::AuthGameState(Game* parent) : GameState(parent)
  {
    _isAuthority = true;
  }

  void AuthGameState::Update(float deltaTime)
  {
    // Update each object
    for (std::list<GameObject*>::iterator objItr = _objList.begin();
      objItr != _objList.end(); objItr++)
    {
      (*objItr)->Update(deltaTime);
    }
  }
  BitStream* AuthGameState::ProcessPacket(Packet* packet)
  {
    return NULL;
  }
}