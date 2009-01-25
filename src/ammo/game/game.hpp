#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "ReplicaManager2.h"

#include "ammo/graphics/graphic_sys.hpp"
#include "ammo/network/netpeer.hpp"
#include "ammo/audio/sound_sys.hpp"
#include "ammo/game/gamestate.hpp"
#include "ammo/physics/physic_sys.hpp"
#include "ammo/graphics/icameratarget.hpp"

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
    PhysicSys* GetPhysicsSys() { return _physic;}

    void SetCameraTarget(ICameraTarget* target) { _camTarget = target;}
  protected:
    GraphicSys* _graphics;
    NetPeer* _peer;
    SoundSys* _sound;
    GameState* _gameState;
    PhysicSys* _physic;
    ICameraTarget* _camTarget;
  };
}

#endif // GAME_H_INCLUDED