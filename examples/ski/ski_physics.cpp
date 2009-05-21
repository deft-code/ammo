#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include "ammo/graphics.hpp"
#include "ammo/audio.hpp"
#include "ammo/physics.hpp"
#include "ammo/game/gameobjects/sampleobject.hpp"

ammo::SampleObject dummy;

b2Vec2 ship_half(4.f,4.f);
b2Vec2 world_half( 40.f, 30.f );

void physic_load( ammo::ActivePhysicSys& sim )
{
	ammo::Circle c;
	c.shape.radius = ship_half.x;
	c.shape.density = 1.f;
	c.shape.friction = 1.f;
	c.shape.restitution = 1.f;
	c.body.position = b2Vec2_zero;
	sim.AddSchema("ship", c);

	ammo::Polygon p;
	p.shape.SetAsBox( world_half.x, 1.f );
	p.shape.density = 0.f;
	p.shape.friction  = 1.f;
	p.shape.restitution = 1.f;
	sim.AddSchema("long_wall", p );
}

int main()
{
	ammo::ActivePhysicSys sim;

	physic_load( sim );

	ammo::Physic top_shape = sim.NewPhysic("long_wall",dummy);
	top_shape.SetPosition( b2Vec2(0.f, world_half.y ) );

	ammo::Physic bottom_shape = sim.NewPhysic("long_wall",dummy);
	bottom_shape.SetPosition( b2Vec2(0.f, -world_half.y ) );

	ammo::Physic ship_shape = sim.NewPhysic("ship",dummy);

	// Create the window of the application
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "SFML Pong");
	App.UseVerticalSync(true);

	ammo::View v(App);
	v.lookAt( b2Vec2_zero );
	v.setWidth( 2*world_half.x );

	ammo::ActiveGraphicSys graphics;

	ammo::SpriteSchema ship_image;
	ship_image.m_filename = "data/tyrian_ships.png";
	ship_image.m_size = 2*ship_half;


	ship_image.m_subrect = sf::IntRect(49,140,49+21,140+27);
	graphics.AddSchema("ship",ship_image);

	ship_image.m_subrect = sf::IntRect(25,140,25+21,140+27);
	graphics.AddSchema("shipL",ship_image);

	ship_image.m_subrect = sf::IntRect(2,140,2+21,140+27);
	graphics.AddSchema("shipLL",ship_image);

	ship_image.m_subrect = sf::IntRect(73,140,73+21,140+27);
	graphics.AddSchema("shipR",ship_image);

	ship_image.m_subrect = sf::IntRect(98,140,98+21,140+27);
	graphics.AddSchema("shipRR",ship_image);

	ammo::Graphic ships[5];
	ships[0] = graphics.NewGraphic("shipLL");
	ships[1] = graphics.NewGraphic("shipL");
	ships[2] = graphics.NewGraphic("ship");
	ships[3] = graphics.NewGraphic("shipR");
	ships[4] = graphics.NewGraphic("shipRR");

	int ship_index = 2;
	ammo::Graphic ship = ships[ship_index];
	ship.show();
	ship.SetZOrder(10.f);

	bool debug_draw = false;
	while ( App.IsOpened() )
	{
		// Handle events
		sf::Event Event;
		while ( App.GetEvent(Event) )
		{
			// Window closed or escape key pressed : exit
			if ( (Event.Type == sf::Event::Closed) || 
				  ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape)) )
			{
				App.Close();
				break;
			}
			if( Event.Type == sf::Event::KeyPressed )
			{
				switch( Event.Key.Code )
				{
				case sf::Key::D:
					if( !debug_draw )
					{
						sim.EnableDebugDraw(graphics,100.f);
					}
					else
					{
						sim.DisableDebugDraw();
					}
					debug_draw = !debug_draw;
					break;
				case sf::Key::Left:
					if( ship_index >= 0 )
					{
						ship.hide();
						--ship_index;
						ship = ships[ship_index];
						ship.show();
						ship.SetZOrder(10.f);
					}
					break;
				case sf::Key::Right:
					if( ship_index < 5 )
					{
						ship.hide();
						++ship_index;
						ship = ships[ship_index];
						ship.show();
						ship.SetZOrder(10.f);
					}
					break;
				}
			}
		}

		sim.Update( App.GetFrameTime() );

		// Player logic
		if ( App.GetInput().IsKeyDown(sf::Key::Left) )
		{	
			ship_shape.SetTheta( ship_shape.GetTheta() + 2.f*App.GetFrameTime() );
		}

		if( App.GetInput().IsKeyDown(sf::Key::Right) )
		{
			ship_shape.SetTheta( ship_shape.GetTheta() - 2.f*App.GetFrameTime() );
		}

		ship.SetPosition( ship_shape.GetPosition() );
		ship.SetRotationRadians( ship_shape.GetTheta() );

		graphics.Update( App.GetFrameTime() );

		// Clear the window
		App.Clear();

		graphics.Draw(App);

		// Display things on screen
		App.Display();
	}

	return EXIT_SUCCESS;
}
