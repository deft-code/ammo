#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP



#include <SFML/Graphics.hpp>
#include "Box2D.h"


namespace ammo
{
  class View;



  class Background
  {
  public:
    Background(sf::RenderWindow* app);
    void Update(b2Vec2 newPos);
    void Draw();
  private:    
    sf::View* _view;
    sf::RenderWindow* _app;
	sf::Image _backImage;
	sf::Sprite _backSprite;

    b2Vec2 _oldPos;
    struct Star
    {
      b2Vec2 _location;
      sf::Color _hue;
      float scale;
    };
    enum
    {
      Max_Stars = 500,
      Speed_Scale = 10
    };

    Star _stars[Max_Stars];

  };
}
#endif // BACKGROUND_HPP