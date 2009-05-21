#ifndef GUIManager_HPP
#define GUIManager_HPP

#include <CEGUI.h>
#include <openglrenderer.h>
#include <SFML/Graphics/RenderWindow.hpp>

namespace ammo
{
  class GUIManager
  {
  public:
    GUIManager():isEnabled(true) {};
    ~GUIManager(){};

    bool Initialize(sf::RenderWindow* Win);
    bool HandleEvent(sf::Event& Event);
    void Draw();

    void Enable() {isEnabled = true;};
    void Disable(){isEnabled = false;};

    CEGUI::System* getSystem() {return mSystem;}
    CEGUI::WindowManager* getWindowManager() {return mWindowManager;}
    void setRootWindow(CEGUI::Window* Win) {mSystem->setGUISheet(Win);}

  private:
    sf::RenderWindow* mWindow;
    const sf::Input* mInput;

    CEGUI::System* mSystem;
    CEGUI::OpenGLRenderer* mRenderer;
    CEGUI::WindowManager* mWindowManager;

    typedef std::map<sf::Key::Code, CEGUI::Key::Scan> KeyMap;
    typedef std::map<sf::Mouse::Button, CEGUI::MouseButton> MouseButtonMap;

    KeyMap mKeyMap;
    MouseButtonMap mMouseButtonMap;

    bool isEnabled;

    void initializeMaps();
    CEGUI::Key::Scan toCEGUIKey(sf::Key::Code Code);
    CEGUI::MouseButton toCEGUIMouseButton(sf::Mouse::Button Button);
  };
}
#endif
