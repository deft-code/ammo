#include "ammo/game/gamestateproxy.hpp"

namespace ammo
{
  ProxyGameState::ProxyGameState(Game* parent) : GameState(parent)
  {
    _isAuthority = false;
  }

  void ProxyGameState::Update(float deltaTime)
  {
    // Update each object
    for (std::list<GameObject*>::iterator objItr = _objList.begin();
      objItr != _objList.end(); objItr++)
    {
      (*objItr)->Update(deltaTime);
    }
  }

  BitStream* ProxyGameState::ProcessPacket(Packet* packet)
  {
    return NULL;
  }
}

