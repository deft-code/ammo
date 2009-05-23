#include "ammo/game/application.hpp"
#include "ammo/util/profiler.hpp"

#include <CEGUI.h>

using CEGUI::UDim;
using CEGUI::UVector2;


namespace ammo
{
  /// Construct the application
  Application::Application() :
    _client(NULL),
    _server(NULL),
    _isDone(false)
  {  }

  /// Load all the applications resources
  bool Application::Initialize()
  {
    // Initialize our renderwindow
    _window.Create(sf::VideoMode(800,600), "ammo");

    // Hide the mouse cursor, let CEGUI handle it
    _window.ShowMouseCursor(false);

    // Initialize the GUI Manager
    if (!_guiMan.Initialize(&_window))
      return false;

    // Create our window with Join/Host/Dedicated Server options
    CEGUI::WindowManager* winMgr = _guiMan.getWindowManager();

    CEGUI::Window* layout = winMgr->loadWindowLayout("data/gui/ammo.layout");

    layout->getChild("root/winserver")->setVisible(false);
    layout->getChild("root/winjoin")->setVisible(false);

    //CEGUI::Window* rootWin = winMgr->createWindow("DefaultWindow", "root");
    //
    //CEGUI::Window* mainWin = winMgr->createWindow("WindowsLook/FrameWindow", "mainWin");
    //mainWin->setMinSize(UVector2(UDim(0.0f, 200),UDim(0.0f, 150)));
    //mainWin->setSize(UVector2(UDim(0.0f, 400),UDim(0.0f, 300)));
    //mainWin->setPosition(UVector2(UDim(0.25f, 0), UDim(0.1f, 0)));
    //mainWin->setText("Welcome to Ammo");
    //mainWin->setProperty("TitlebarEnabled", "False");
    //mainWin->setProperty("CloseButtonEnabled", "False");
    //mainWin->setProperty("SizingEnabled", "False");

    //CEGUI::Window* btnJoin = winMgr->createWindow("WindowsLook/Button", "btnJoin");
    //btnJoin->setMinSize(UVector2(UDim(0.0f, 100), UDim(0.0f, 20)));
    //btnJoin->setSize(UVector2(UDim(0.5f, 0), UDim(0.1f, 0)));
    //btnJoin->setPosition(UVector2(UDim(0.25f, 0), UDim(0.4f, 0)));
    //btnJoin->setText("Join Game");

    //CEGUI::Window* btnHost = winMgr->createWindow("WindowsLook/Button", "btnHost");
    //btnHost->setMinSize(UVector2(UDim(0.0f, 100), UDim(0.0f, 20)));
    //btnHost->setSize(UVector2(UDim(0.5f, 0), UDim(0.1f, 0)));
    //btnHost->setPosition(UVector2(UDim(0.25f, 0), UDim(0.5f, 0)));
    //btnHost->setText("Host Game");


    //
    //mainWin->addChildWindow(btnJoin);
    //mainWin->addChildWindow(btnHost);

    //// Create our hidden windows for creating a server and joining a server
    //CEGUI::Window* servWin = winMgr->createWindow("WindowsLook/FrameWindow", "winMakeServer");
    ////servWin->setModalState(true);
    //servWin->setMinSize(UVector2(UDim(0.0f, 200),UDim(0.0f, 150)));
    //servWin->setSize(UVector2(UDim(0.0f, 200),UDim(0.0f, 200)));
    //servWin->setPosition(UVector2(UDim(0.5f, 0), UDim(0.5f, 0)));
    //servWin->setText("Welcome to Ammo");
    //servWin->setProperty("TitlebarEnabled", "False");
    //servWin->setProperty("CloseButtonEnabled", "False");
    //servWin->setProperty("SizingEnabled", "False");
    //servWin->hide();
    //
    //CEGUI::Window* lblPort = winMgr->createWindow("WindowsLook/StaticText","lblServPort");
    //lblPort->setText("Port: (1025-65535)");
    //servWin->addChildWindow(lblPort);
    //rootWin->addChildWindow(mainWin);
    //rootWin->addChildWindow(servWin);
    //mainWin->activate();

    winMgr->getWindow("root/main/btnhost")->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&Application::OnHostClick, this));
    winMgr->getWindow("root/main/btnjoin")->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&Application::OnJoinClick, this));
    winMgr->getWindow("root/winserver/btncancel")->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&Application::OnServCancelClick, this));
    winMgr->getWindow("root/winjoin/btncancel")->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&Application::OnJoinCancelClick, this));
    winMgr->getWindow("root/winserver/btnhost")->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&Application::OnServStartClick, this));
    winMgr->getWindow("root/winjoin/btnjoin")->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&Application::OnJoinStartClick, this));

    _guiMan.setRootWindow(layout);

    return true;
  }
  /// Launch the application
  void Application::Run()
  {
    sf::Clock clock;
    sf::Event myEvent;
    float dt = 0;    
    // TODO:
    // Allow us to create a server, and be able to quit gracefully
    while (!_isDone)
    {        
      dt = clock.GetElapsedTime();
      PROFILE_NEXT_FRAME(dt);
      clock.Reset();

      _window.Clear();
      while (_window.GetEvent(myEvent))
      {
        //See if CEGUI should handle it
        if (_guiMan.HandleEvent(myEvent))
          continue;

        switch (myEvent.Type)
        {
        case sf::Event::Closed:
          _window.Close();     
          _isDone = true;
          break;
        case sf::Event::KeyPressed:
          if (myEvent.Key.Code == sf::Key::Escape)
            //Stop();
            break;
        default: break;//ignore
        }
      }

      if (_client && !_isDone)
      {
        PROFILE_TIMER(client)
        _client->Draw(dt);
        _client->Update(dt);
      }
      if (_server && !_isDone)
      {
        PROFILE_TIMER(server)
        _server->Update(dt);      
      }
      _guiMan.Draw();
      _window.Display();
    }

    if (_client)
    {
      delete _client;
    }

    if (_server)
    {
      dt = clock.GetElapsedTime();

      _server->Update(dt);      
      delete _server;
    }
  }

  bool Application::OnHostClick(const CEGUI::EventArgs &e)
  {
    std::cout << "Host clicked." << std::endl;
    CEGUI::Window* servWin = _guiMan.getWindowManager()->getWindow("root/winserver");

    servWin->show();
    servWin->activate();
    servWin->setModalState(true);
    return true;
  }
  bool Application::OnJoinClick(const CEGUI::EventArgs& e)
  {
    std::cout << "Join clicked." << std::endl;
    CEGUI::Window* servWin = _guiMan.getWindowManager()->getWindow("root/winjoin");

    servWin->show();
    servWin->activate();
    servWin->setModalState(true);
    return true;
  }

  // Server window callbacks
  bool Application::OnServStartClick(const CEGUI::EventArgs& e)      
  {    
    // Get the server port
    int port = 0;
    int maxConns=1;

    // Get the port
    CEGUI::Window* txtWin = _guiMan.getWindowManager()->getWindow("root/winserver/inport");
    port = atoi(txtWin->getText().c_str());
    // Get the host
    txtWin = _guiMan.getWindowManager()->getWindow("root/winserver/inmaxplayers");
    CEGUI::String mString = txtWin->getText();
    std::string myString(mString.c_str());
        
    maxConns = atoi(txtWin->getText().c_str());

    _server =  new ammo::Server(port, maxConns);
    std::cout << "Sleeping while server boots" << std::endl;
  #ifdef WIN32
    Sleep(500);
  #else
    usleep(500*1000);
  #endif
    std::cout << "Server online." << std::endl;

    _client = new ammo::Client(&_window);
    _client->Connect("localhost", port,"",0);

    _guiMan.Disable();
    CEGUI::Window* servWin = _guiMan.getWindowManager()->getWindow("Root");
    servWin->deactivate();
    servWin->setModalState(false);
    servWin->setVisible(false);
    return true;
  }

  bool Application::OnServCancelClick(const CEGUI::EventArgs& e)     
  {
    CEGUI::Window* servWin = _guiMan.getWindowManager()->getWindow("root/winserver");

    servWin->deactivate();
    servWin->setModalState(false);
    servWin->setVisible(false);

    return true;
  }

  // Join window callbacks
  bool Application::OnJoinStartClick(const CEGUI::EventArgs& e)
  {    
    int clientPort = 0;

    // Get the port
    CEGUI::Window* txtWin = _guiMan.getWindowManager()->getWindow("root/winjoin/inport");
    clientPort = atoi(txtWin->getText().c_str());
    // Get the host
    txtWin = _guiMan.getWindowManager()->getWindow("root/winjoin/inip");
    _client = new ammo::Client(&_window);
    _client->Connect(txtWin->getText().c_str(), clientPort,"",0);

    _guiMan.Disable();
    CEGUI::Window* servWin = _guiMan.getWindowManager()->getWindow("Root");
    servWin->deactivate();
    servWin->setModalState(false);
    servWin->setVisible(false);
    return true;
  }

  bool Application::OnJoinCancelClick(const CEGUI::EventArgs& e)
  {    
    CEGUI::Window* servWin = _guiMan.getWindowManager()->getWindow("root/winjoin");
    
    servWin->deactivate();
    servWin->setModalState(false);
    servWin->setVisible(false);

    return true;
  }

}
