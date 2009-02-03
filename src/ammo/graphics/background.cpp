#include "ammo/graphics/background.hpp"

#include "ammo/graphics/view.hpp"
#include "ammo/util/profiler.hpp"

namespace ammo
{
  Background::Background(sf::RenderWindow* app)
  {
    // Store our app
    _app = app;
    
    // Create our 'HUD' view    
    _view = new sf::View(sf::Vector2<float>(app->GetWidth()* .5f, app->GetHeight()*.5f),
    sf::Vector2<float>(app->GetWidth()* .5f, app->GetHeight()*.5f));
    // Load our star sprite
    _starImage.LoadFromFile("data/star.png");
    
    // Initialize our oldPos vector
    _oldPos = b2Vec2(0.f,0.f);
    
    // Initialize our stars
    for (int i = 0; i<Max_Stars; i++)
    {
      _stars[i]._sprite.SetImage(_starImage);
      // Stars sit in a square 100 px around our screen
      _stars[i]._location.x = sf::Randomizer::Random(-100.f, app->GetWidth() + 100.f);
      _stars[i]._location.y = sf::Randomizer::Random(-100.f, app->GetHeight() + 100.f);
      // Initialize their scale, how fast they parrallaxalize
      _stars[i].scale = sf::Randomizer::Random(.01f, 1.f);
      // And their color, more distant stars are more transparent.
      // TODO 
      // add some color to these stars
      _stars[i]._hue = sf::Color::White;
      _stars[i]._hue.a *= _stars[i].scale;
      _stars[i]._sprite.SetColor(_stars[i]._hue);
    }
  }

  void Background::Update(b2Vec2 newPos)
  {
    b2Vec2 deltaPos = newPos - _oldPos;// Get our delta posistion
    _oldPos = newPos; // Store the new position
    deltaPos *= Speed_Scale; // Increase the size of this vector by a scale

    // Update the position of all our stars
    for (int i = 0; i < Max_Stars; i++)
    {
      // Curse you inverted y axis!
      _stars[i]._location.x -= deltaPos.x * _stars[i].scale;
      _stars[i]._location.y += deltaPos.y * _stars[i].scale;

      // Move our stars over
      if (_stars[i]._location.x< -100.f)
        _stars[i]._location.x+= 1000.f;
      if (_stars[i]._location.x>900.f)
        _stars[i]._location.x -= 1000.f;
      if (_stars[i]._location.y < -100.f)
        _stars[i]._location.y += 800.f;
      if (_stars[i]._location.y > 700.f)
        _stars[i]._location.y -= 800.f;
      _stars[i]._sprite.SetPosition( _stars[i]._location.x, _stars[i]._location.y);
    }
  }

  void Background::Draw()
  {    
    PROFILE_TIMER(background_draw)
    // Use our view
    _app->SetView(*(_view));

    // Draw our stars
    for (int i = 0; i < Max_Stars; i++)
    {      

      //_starSprite.SetPosition(_stars[i]._location.x, _stars[i]._location.y);
      //_starSprite.SetColor(_stars[i]._hue);
      _app->Draw(_stars[i]._sprite);
    }   
  }
}