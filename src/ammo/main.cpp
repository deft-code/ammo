#include "ammo/graphics.hpp"
#include "ammo/audio.hpp"
#include "ammo/gameincludes.hpp"

#include <iostream>

int main()
{
   std::cout << "hello world!\n";

   ammo::Server* _server = new ammo::Server();
   system("PAUSE");
   delete _server;
   system("PAUSE");
}
