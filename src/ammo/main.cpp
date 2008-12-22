#include "ammo/graphics.hpp"
#include "ammo/audio.hpp"
#include "ammo/gameincludes.hpp"

#include <iostream>
#include "SFML/System.hpp"

using std::cout;
using std::endl;
using std::string;

int main()
{
  cout << "Welcome to Ammo!" << endl;

  // I realize that this is not the clean or right way to 
  // handle this

  // But it's a quick and dirty way until we establish a graphical
  // or ini based or whatevah
  bool canProceed = false;
  string setupOption = "n";

  while (!canProceed)
  {
    cout << "Would you like to open a (c)lient, (s)erver, or (b)oth? ";
    std::cin >>setupOption;

    if (setupOption == "c" || setupOption == "s" || setupOption == "b")
    {
      canProceed = true;
    }
    else
    {
      cout << setupOption << " is not a valid option." << endl;
    }
  }

  // Our server, initially NULL
  ammo::Server* _server = NULL;
  // Our client, initially NULL
  ammo::Client* _client = NULL;

  if (setupOption == "s" || setupOption == "b")
  {
    unsigned short port = 0;
    unsigned short maxConns = 0;
    cout << "Creating Server." << endl;
    // Get the server port
    while (port < 1024 || port > 65535)
    {
      cout << "Input Port (1025-65535): ";
      std::cin >> port;
    }
    // Get the server max connections
    while (maxConns < 1 || maxConns > 64)
    {
      cout << "Maximum incoming connections (1-64): ";
      std::cin >> maxConns;
    }

    // Wait for the server to get up and ready
    _server =  new ammo::Server(port, maxConns);
    std::cout << "Sleeping while server boots" << std::endl;
#ifdef WIN32
    Sleep(500);
#else
    usleep(500*1000);
#endif
    cout << "Server online." << endl;
  }

  // Setup the client
  if (setupOption == "c" || setupOption == "b")
  {
    cout << "Creating Client:" << endl;      
    int clientPort = 0;
    string clientHost = "";

    // Not going to do much typechecking here
    while (clientHost.length() < 7 || clientHost.length() > 15)
    {
      cout << "Input server IP: ";
      std::cin >> clientHost;
    }

    while (clientPort < 1025 || clientPort > 65535 )
    {
      cout << "Input target port (1025-65535): ";
      std::cin >> clientPort;
    }

    _client = new ammo::Client();
    _client->Connect(clientHost.c_str(), clientPort,"",0);
    
  }



  sf::Clock clock;
  float dt = 0;
  string terminalInput = "";
  // TODO:
  // Allow us to create a server, and be able to quit gracefully
  while (_client == NULL || _client->GetIsDestroyed() == false)
  {    
    dt = clock.GetElapsedTime();
    clock.Reset();
    if (_client)
    {
      _client->Draw(dt);
      _client->Update(dt);
    }
    if (_server)
    {
      _server->Update(dt);      
    }
  }

  if (_client)
  {
    delete _client;
  }

  if (_server)
  {
    dt = clock.GetElapsedTime();

    _server->Update(dt);
    system("PAUSE");

    delete _server;
    
  }

  system("PAUSE");
  return EXIT_SUCCESS;
}
