#include "ammo/graphics.hpp"
#include "ammo/audio.hpp"
#include "ammo/gameincludes.hpp"
#include "ammo/util/profiler.hpp"

#include <iostream>
#include <stdlib.h>

#include "SFML/System.hpp"
#include "ammo/game/application.hpp"

using std::cout;
using std::endl;
using std::string;
using std::cin;



int main()
{
  ammo::Application app;

  if (!app.Initialize())
  {
    cout << "Application failed to initialize properly." << endl;
    system("PAUSE");
  }

  app.Run();

  PROFILE_WRITE_DATA();
  return EXIT_SUCCESS;
}
