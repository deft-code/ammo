#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#include "ammo/game/game.hpp"
#include "SFML/Graphics.hpp"
#include "ammo/graphics.hpp"
#include "ammo/graphics/background.hpp"

namespace ammo
{
  class Client : public Game
  {
  public:
    Client();
    ~Client();
    
    void Draw(float deltaTime);
    void Update(float deltaTime);
    // Whether the user has attempted to close this client
    bool GetIsDestroyed();
    // Connects this client to a server. 
    // returns true if the attempt to connect is successful, not if the
    // actual connection occurs.
    bool Connect(const char* host,unsigned short remotePort, const char* passwordData,int pwdDataLength);

  private:
    sf::RenderWindow* _app;
    sf::Event myEvent;    
    bool _isDestroyed;
    ammo::View* _view;
    ammo::Background* _background;
  };
}

#endif // CLIENT_H_INCLUDED