#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED

#include "ammo/game/game.hpp"

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
  };
}


#endif