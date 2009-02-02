#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED

#include "ammo/game/game.hpp"
#include "RakNetTypes.h"
#include "ammo/game/gameobjects/playerobject.hpp"


namespace ammo
{
  
  class Server : public Game
  {
  public:
    Server(unsigned short portNum, unsigned int maxConns);
    ~Server();
    
    void Draw(float deltaTime);
    void Update(float deltaTime);
  private:
    std::map<SystemAddress,ammo::PlayerObject*> _players;
  };
}


#endif