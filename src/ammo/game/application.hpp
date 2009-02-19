#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "ammo/game/client.hpp"
#include "ammo/game/server.hpp"
#include "ammo/gui/gui_manager.hpp"

namespace ammo
{
  class Application
  {
  public:
    Application();

    bool Initialize();
    void Run();

    // Main window callbacks:
    bool OnHostClick(const CEGUI::EventArgs& e);
    bool OnJoinClick(const CEGUI::EventArgs& e);

    // Server window callbacks
    bool OnServStartClick(const CEGUI::EventArgs& e);
    bool OnServCancelClick(const CEGUI::EventArgs& e);

    // Join window callbacks
    bool OnJoinStartClick(const CEGUI::EventArgs& e);
    bool OnJoinCancelClick(const CEGUI::EventArgs& e);
  private:
    GUIManager _guiMan; // That's right, the amazing GUI-Man! He's here to save the day.
    Client* _client;
    Server* _server;
    sf::RenderWindow _window;
    bool _isDone;

    
  };
}
#endif // APPLICATION_HPP