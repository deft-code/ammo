#include "ammo/graphics.hpp"
#include "ammo/audio.hpp"
#include "ammo/gameincludes.hpp"

#include <iostream>
#include "SFML/System.hpp"

int main()
{
   std::cout << "hello world!\n";

   ammo::Server* _server = new ammo::Server();
      // Wait for the server to get up and ready
   std::cout << "Sleeping while server boots" << std::endl;
  #ifdef WIN32
	  Sleep(500);
  #else
	  usleep(500*1000);
  #endif
   ammo::Client* _client = new ammo::Client();



   _client->Connect("127.0.0.1", 31337,"",0);
   sf::Clock clock;
   float dt = 0;
   while (_client->GetIsDestroyed() == false)
   {    
     dt = clock.GetElapsedTime();
     clock.Reset();
     _client->Draw(dt);
     _client->Update(dt);
     _server->Update(dt);
   }

   delete _client;
   dt = clock.GetElapsedTime();
   _server->Update(dt);
   system("PAUSE");

   delete _server;
   system("PAUSE");
}
