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
	_backImage.Create(app->GetWidth(), app->GetHeight());
	_backSprite.SetImage(_backImage);
    
    // Initialize our oldPos vector
    _oldPos = b2Vec2(0.f,0.f);
    
    // Initialize our stars
    for (int i = 0; i<Max_Stars; i++)
    {
      // Stars sit on an image the size of our screen
      _stars[i]._location.x = sf::Randomizer::Random(0.f, app->GetWidth()-1.f);
      _stars[i]._location.y = sf::Randomizer::Random(0.f, app->GetHeight()-1.f);
      // Initialize their scale, how fast they parrallaxalize
      _stars[i].scale = sf::Randomizer::Random(.01f, 1.f);
      // And their color, more distant stars are more transparent.
      // TODO 
      // add some color to these stars
      _stars[i]._hue = sf::Color::White;
      _stars[i]._hue.a *= _stars[i].scale;
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
		// Draw their current locations black
		_backImage.SetPixel(_stars[i]._location.x, _stars[i]._location.y, sf::Color::Black);
      // Curse you inverted y axis!
      _stars[i]._location.x -= deltaPos.x * _stars[i].scale;
      _stars[i]._location.y += deltaPos.y * _stars[i].scale;

      // Move our stars over
      if (_stars[i]._location.x< 0.f)
        _stars[i]._location.x+= 800.f;
      if (_stars[i]._location.x>=800.f)
        _stars[i]._location.x -= 800.f;
      if (_stars[i]._location.y < 0.f)
        _stars[i]._location.y += 600.f;
      if (_stars[i]._location.y >= 600.f)
        _stars[i]._location.y -= 600.f;      

	  // draw their new locations white
	  _backImage.SetPixel(_stars[i]._location.x, _stars[i]._location.y, _stars[i]._hue);
    }
  }

  void Background::Draw()
  {    
    PROFILE_TIMER(background_draw)
    // Use our view
    _app->SetView(*(_view));

    // Draw our stars
	_app->Draw(_backSprite);

  }
}