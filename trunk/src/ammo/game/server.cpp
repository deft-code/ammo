#include "ammo/game/server.hpp"

#include "RakNetTypes.h"
#include "MessageIdentifiers.h"
#include <iostream>

namespace ammo 
{

  Server::Server()
  {
    _peer = new NetPeer(this, true);
    _gameState = NULL;
    _graphics = NULL;
    _sound = NULL;
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
      std::cout << "SERVER: Packet Received from: "<< packet->systemAddress.ToString() << std::endl;
      switch (packet->data[0])
      {
      case ID_CONNECTION_ATTEMPT_FAILED:
        printf("ID_CONNECTION_ATTEMPT_FAILED\n");				
        break;
      case ID_NO_FREE_INCOMING_CONNECTIONS:
        printf("ID_NO_FREE_INCOMING_CONNECTIONS\n");				
        break;
      case ID_CONNECTION_REQUEST_ACCEPTED:
        printf("ID_CONNECTION_REQUEST_ACCEPTED\n");				
        break;
      case ID_NEW_INCOMING_CONNECTION:				
        printf("ID_NEW_INCOMING_CONNECTION from %s\n", packet->systemAddress.ToString());    					
        break;
      case ID_DISCONNECTION_NOTIFICATION:
        printf("ID_DISCONNECTION_NOTIFICATION\n");				
        break;
      case ID_CONNECTION_LOST:
        printf("ID_CONNECTION_LOST\n");				
        break;
      default:
        printf("UNKNOWN PACKET TYPE: %i", packet->data[0]);
        break;
      }
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