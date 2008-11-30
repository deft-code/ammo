#include "ammo/game/server.hpp"

#include "RakNetTypes.h"

#include <iostream>

namespace ammo 
{

  Server::Server()
  {
    _peer = new NetPeer(this, true);
  }

  Server::~Server()
  {
    delete _peer;
  }

  void Server::Draw(float deltaTime)
  {
    // We could draw our graphics system here, if we wanted
    // Or log some things, or draw monkeys

    // Yeah, we should totally draw monkeys
  }


  // deltaTime - the change in time (in seconds) since the last
  // frame.
  void Server::Update(float deltaTime)
  {
    // Our main update loop for the server
    Packet* packet;
    // Grab all packets, handing them to the gamestate
    for (packet = _peer->Receive(); packet != NULL; _peer->DeallocatePacket(packet), packet = _peer->Receive())
    {      
      std::cout << "Packet Received from: "<< packet->systemAddress.ToString() << std::endl;
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
}