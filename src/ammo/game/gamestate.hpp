#ifndef GAMESTATE_H_INCLUDED
#define GAMESTATE_H_INCLUDED

#include "RakNetTypes.h"
#include "ammo/game/gameobject.hpp"
#include "ammo/game/game.hpp"

namespace ammo
{
  // Usings and forward declarations
  using RakNet::BitStream;
  class Game;
  // This is the base class for the proxy and authority
  // gamestates. The gamestate is responsible for updating
  // game objects, and passing messages between game objects.
  // It also receives packets and acts on them appropriately
  class GameState
  {
  public:
    // Updates all the Game Objects in the game state.
    virtual void Update(float deltaTime)=0;
    // Packets received by the server are handed to the gamestate
    // via this method. The gamestate can optionally return a bitstream
    // to be broadcast out. 
    virtual BitStream* ProcessPacket(Packet* packet)=0;
    // Registers a GameObject with the gamestate, so that it can be
    // updated and receive any messages it needs to receive
    // This method will (likely) store the object in an internal map.    
    virtual void RegisterGameObject(GameObject* object);

  protected:
    Game* _parent;
  };
}
#endif // GAMESTATE_H_INCLUDED