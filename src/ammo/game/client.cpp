#include "ammo/game/client.hpp"
#include "ammo/game/gamestateproxy.hpp"
#include "ammo/graphics.hpp"
#include "ammo/audio.hpp"
#include "ammo/physics.hpp"

#include "RakNetTypes.h"
#include "MessageIdentifiers.h"
#include <iostream>

namespace ammo 
{

  Client::Client()
  {
    // Set up our renderwindow
    // TODO: Don't hardcode values here.
    _app = new sf::RenderWindow(sf::VideoMode(800, 600), "CLIENT TEST");
    // Set up our viewport
    // TODO: Don't Hardcode these!
    _view = new ammo::View(*_app);
    _view->setWidth(800);
    _view->setHeight(600);
    _view->lookAt(b2Vec2(300, 300));

    _gameState = new ProxyGameState(this);
    _graphics = new ActiveGraphicSys();
    // Register our graphics with the client:
    // TODO: Don't hardcode these!
    _graphics->AddBluePrint("player", SpriteDef("data/red_paddle.png"));


    _sound = new ActiveSoundSys();
    // Add some test sounds
    // TODO: Don't hardcode these
    _sound->AddBluePrint("player", PlainDef("data/ball.wav"));
    

    // Create the Physics System
    _physic = new PassivePhysicSys();
    

    _peer = new NetPeer(this, false);
    _isDestroyed = false;
  }

  Client::~Client()
  {
    delete _graphics;
    delete _gameState;
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
      if (myEvent.Type == sf::Event::Closed)
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
      switch (packet->data[0])
      {
      case ID_CONNECTION_ATTEMPT_FAILED:
      case ID_CONNECTION_BANNED:
        std::cout << "Connection to remote host failed." << std::endl;
        break;
      default:
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

    // Update our camera
    if (_camTarget)
    {
      _view->lookAt(_camTarget->GetPosition());
    }    
  }

  bool Client::Connect(const char* host,unsigned short remotePort, const char* passwordData,int pwdDataLength)
  {
    return _peer->Connect(host, remotePort, passwordData, pwdDataLength);
  }
}