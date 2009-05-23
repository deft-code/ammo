#ifndef GAMESTATEAUTH_H_INCLUDED
#define GAMESTATEAUTH_H_INCLUDED

#include "ammo/game/gamestate.hpp"

namespace ammo
{
  // The authority gamestate is the server side
  // gamestate. It is responsible for maintaining
  // the true state of the game.
  class AuthGameState : public GameState
  {
  public:
    AuthGameState(Game* parent);
    void Update(float deltaTime);
    BitStream* ProcessPacket(Packet* packet);
  };
}
#endif // GAMESTATEAUTH_H_INCLUDED

