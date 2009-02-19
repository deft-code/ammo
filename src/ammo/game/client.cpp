#include "ammo/game/client.hpp"
#include "ammo/game/gamestateproxy.hpp"
#include "ammo/graphics.hpp"
#include "ammo/audio.hpp"
#include "ammo/physics.hpp"
#include "ammo/util/profiler.hpp"

#include "ammo/input/single_key_boolean.hpp"

#include "RakNetTypes.h"
#include "MessageIdentifiers.h"
#include <iostream>

namespace ammo 
{

  Client::Client(sf::RenderWindow* app)
  {
    // Set up our renderwindow
    // TODO: Don't hardcode values here.
    _app = app;
    // Set up our viewport
    // TODO: Don't Hardcode these!
    _view = new ammo::View(*_app);
    _view->setWidth(40);
    _view->lookAt(b2Vec2(0, 0));
    
    _background = new ammo::Background(_app);

    _gameState = new ProxyGameState(this);
    _graphics = new ActiveGraphicSys();
    // Register our graphics with the client:
    // TODO: Don't hardcode these!
    _graphics->AddSchema("player", SpriteDef("data/ship256.png"));

    _sound = new ActiveSoundSys();
    // Add some test sounds
    // TODO: Don't hardcode these
    _sound->AddBluePrint("player", PlainDef("data/ball.wav"));
    
    // Create the Physics System
    _physic = new PassivePhysicSys();
    // Create our physics blueprints
    // TODO: Create these from a file
    Polygon myPoly;   
    myPoly.body_blueprint.allowSleep = false;
    myPoly.polygon_blueprint.density = .1f;
    myPoly.polygon_blueprint.friction = 0;
    myPoly.polygon_blueprint.SetAsBox(.48f, 1.28f);             
    _physic->AddBluePrint("player", myPoly);
    _peer = new NetPeer(this, false);
    
    // Create our input system
    _input = new InputSys();
  }

  Client::~Client()
  {
    delete _graphics;
    delete _gameState;
    delete _peer;
    delete _sound;
    delete _physic;
    delete _input;
  }

  void Client::Draw(float deltaTime)
  {    
    PROFILE_TIMER(client_draw)
    if (_graphics)
    {
      _background->Draw();
      _view->update_view();
      _graphics->Draw(*_app);
    }
  }

  // deltaTime - the change in time (in seconds) since the last
  // frame.
  void Client::Update(float deltaTime)
  {
    // Our main update loop for the server
    Packet* packet;
    // Grab all packets, handing them to the gamestate
    for (packet = _peer->Receive(); packet != NULL; _peer->DeallocatePacket(packet), packet = _peer->Receive())
    {      
      PROFILE_TIMER(client_packetPump)
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
      PROFILE_TIMER(client_gamestate)
      _gameState->Update(deltaTime);
    }
    
    if (_graphics)
    {
      PROFILE_TIMER(client_graphics)
      _graphics->Update(deltaTime);
    }
    if (_sound)
    {
      PROFILE_TIMER(client_sound)
      _sound->update(deltaTime);
    }   
    if (_physic)
    {
      PROFILE_TIMER(client_physic)
      _physic->Update(deltaTime);    
    }
    if (_input)
    {
      PROFILE_TIMER(client_input)
      _input->Update(_app->GetInput(), deltaTime);
    }
    // Update our camera
    if (_camTarget)
    {
      PROFILE_TIMER(client_background)
      _background->Update(_camTarget->GetPosition());
      _view->lookAt(_camTarget->GetPosition());
    }    
  }

  bool Client::Connect(const char* host,unsigned short remotePort, const char* passwordData,int pwdDataLength)
  {
    
    bool result = _peer->Connect(host, remotePort, passwordData, pwdDataLength);

    if (result)
    {
    #ifdef WIN32
        Sleep(500);
    #else
        usleep(500*1000);
    #endif
    std::vector<ammo::InputAction*> actions;
    actions.push_back(new SingleKeyBoolean(sf::Key::W, enums::THRUST));
    actions.push_back(new SingleKeyBoolean(sf::Key::A, enums::LEFT));
    actions.push_back(new SingleKeyBoolean(sf::Key::D, enums::RIGHT));
    actions.push_back(new SingleKeyBoolean(sf::Key::S, enums::REVERSE));
    actions.push_back(new SingleKeyBoolean(sf::Key::LControl, enums::AFTERBURN));
    //actions.push_back(// Some input action
    _input->AddInputMap(_peer->GetLocalAddress(), actions);
    }

    return result;
  }
}