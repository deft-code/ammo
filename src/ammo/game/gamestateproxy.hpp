#ifndef GAMESTATEPROXY_H_INCLUDED
#define GAMESTATEPROXY_H_INCLUDED

#include "ammo/game/gamestate.hpp"

namespace ammo
{
  // The authority gamestate is the server side
  // gamestate. It is responsible for maintaining
  // the true state of the game.
  class ProxyGameState : public GameState
  {
  public:
    ProxyGameState(Game* parent);
    void Update(float deltaTime);
    BitStream* ProcessPacket(Packet* packet);
  };
}
#endif // GAMESTATEPROXY_H_INCLUDED

