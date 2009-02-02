#ifndef GAMESTATE_H_INCLUDED
#define GAMESTATE_H_INCLUDED

#include "RakNetTypes.h"
#include "ammo/game/gameobject.hpp"
#include "ammo/game/game.hpp"

#include "ammo/graphics/icameratarget.hpp"

#include <list>

namespace ammo
{
  // Usings and forward declarations
  using RakNet::BitStream;
  class Game;
  class GameObject;
  // This is the base class for the proxy and authority
  // gamestates. The gamestate is responsible for updating
  // game objects, and passing messages between game objects.
  // It also receives packets and acts on them appropriately
  class GameState
  {
  public:
    GameState(Game* parent);
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
  
    // Removes a game object from the game world correctly.
    // This may potentially cause the object to be deserialized over the connection.
    virtual void UnregisterGameObject(GameObject* object);

    // Returns a boolean indicating whether this game stat is a client or
    // a server (true)
    bool  GetIsAuthority(){ return _isAuthority; }

    // Sets the target of the Gamestate
    void SetTarget(ICameraTarget* target);

  protected:
    // Whether this gamestate is an authority or not.
    bool _isAuthority;
    // The list of objects this gamestate is maintaining
    std::list<GameObject*> _objList;
    // A pointer to the game (client or server) that owns this object
    Game* _parent;
  };
}
#endif // GAMESTATE_H_INCLUDED