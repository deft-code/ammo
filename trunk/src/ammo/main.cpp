#include "ammo/graphics.hpp"
#include "ammo/audio.hpp"
#include "ammo/gameincludes.hpp"

#include <iostream>

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
   while (_client->GetIsDestroyed() == false)
   {     
     _client->Draw(0);
     _client->Update(0);
     _server->Update(0);
   }

   delete _client;
   _server->Update(0);
   system("PAUSE");

   delete _server;
   system("PAUSE");
}
