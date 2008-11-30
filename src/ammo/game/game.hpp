#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "ReplicaManager2.h"

#include "ammo/graphics/graphic_sys.hpp"
#include "ammo/network/netpeer.hpp"
#include "ammo/audio/sound_sys.hpp"
#include "ammo/game/gamestate.hpp"

namespace ammo
{
  class NetPeer;
  class GameState;

  class Game
  {
  public:
    virtual void Update(float deltaTime) = 0;
    virtual void Draw(float deltaTime) = 0;    

    // Getters
    GraphicSys* GetGraphicSys(){ return _graphics;}
    NetPeer* GetNetPeer(){return _peer;}
    SoundSys* GetSoundSys() {return _sound;}
    GameState* GetGameState() { return _gameState;}

  protected:
    GraphicSys* _graphics;
    NetPeer* _peer;
    SoundSys* _sound;
    GameState* _gameState;
  };
}

#endif // GAME_H_INCLUDED