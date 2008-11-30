#include "ammo/game/client.hpp"

#include "RakNetTypes.h"

#include <iostream>

namespace ammo 
{

  Client::Client()
  {
    _app = new sf::RenderWindow(sf::VideoMode(800, 600), "CLIENT TEST");
    _gameState = NULL;
    _graphics = NULL;
    _sound = NULL;
    _peer = new NetPeer(this, false);
    _isDestroyed = false;
  }

  Client::~Client()
  {
    delete _peer;
  }

  void Client::Draw(float deltaTime)
  {
    _app->Clear();

    if (_graphics)
    {
      _graphics->draw(*_app);
    }

    _app->Display();
  }

  bool Client::GetIsDestroyed()
  {
    return _isDestroyed;
  }
  // deltaTime - the change in time (in seconds) since the last
  // frame.
  void Client::Update(float deltaTime)
  {
    // Pump our application messages
    while (_app->GetEvent(myEvent))
    {
      if (myEvent.Type == sf::Event::EventType::Closed)
      {
        // We'll eventually want to close our whole application
        _app->Close();
        _isDestroyed = true;
        return;
      }
    }
    // Our main update loop for the server
    Packet* packet;
    // Grab all packets, handing them to the gamestate
    for (packet = _peer->Receive(); packet != NULL; _peer->DeallocatePacket(packet), packet = _peer->Receive())
    {      
      std::cout << "CLIENT: Packet Received from: "<< packet->systemAddress.ToString() << std::endl;
    }


    // Update all our child objects
    if (_gameState)
    {
      _gameState->Update(deltaTime);
    }
    if (_graphics)
    {
      _graphics->update(deltaTime);
    }
    if (_sound)
    {
      _sound->update(deltaTime);
    }
  }

  bool Client::Connect(const char* host,unsigned short remotePort, const char* passwordData,int pwdDataLength)
  {
    return _peer->Connect(host, remotePort, passwordData, pwdDataLength);
  }
}