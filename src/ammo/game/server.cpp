#include "ammo/game/server.hpp"
#include "ammo/game/gameobjects/gameobjectlist.hpp"
#include "ammo/game/gamestateauth.hpp"
#include "ammo/graphics.hpp"
#include "ammo/audio.hpp"
#include "ammo/physics.hpp"

#include "RakNetTypes.h"
#include "MessageIdentifiers.h"
#include <iostream>

namespace ammo 
{

  Server::Server(unsigned short portNum, unsigned int maxConns)
  {
    _peer = new NetPeer(this, true, portNum, maxConns );
    _gameState = new AuthGameState(this);
    _graphics = new PassiveGraphicSys();
    _sound = new PassiveSoundSys();
    _physic = new ActivePhysicSys();
    _input = new InputSys();
    std::vector<ammo::InputAction*> actions;
    _input->AddInputMap("player", actions);
    // Add our Physics Blueprints
    // TODO: Read these from some sort of file
    Polygon myPoly;
    myPoly.polygon_blueprint.density = 1;
    myPoly.polygon_blueprint.SetAsBox(4.8f, 12.8f);//, b2Vec2(4.8f, 12.8f), 0.0f);
    _physic->AddBluePrint("player", myPoly);
  }

  Server::~Server()
  {
    delete _peer;
    delete _gameState;
    delete _graphics;
    delete _sound;
    delete _physic;
    delete _input;
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
    // TEMPORARY
    // TODO
    GameObject* newPlayer = NULL;

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
        // When a new player connects, we need to add that player object to the game
        newPlayer = new PlayerObject(packet->systemAddress);
        newPlayer->AddAutoSerializeTimer(0);        
        _gameState->RegisterGameObject(newPlayer);

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
    if (_physic)
    {
      _physic->Update(deltaTime);
    }
  }
}