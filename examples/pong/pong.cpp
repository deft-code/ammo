#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include "ammo/graphics.hpp"
#include "ammo/audio.hpp"
#include "ammo/physics.hpp"
#include "ammo/game/gameobjects/sampleobject.hpp"

ammo::SampleObject dummy;

b2Vec2 ball_half(1.f,1.f);
b2Vec2 paddle_half( 1.f, 4.f );
b2Vec2 world_half( 40.f, 30.f );

void physic_load( ammo::ActivePhysicSys& sim )
{
	ammo::Circle c;
	c.circle_blueprint.radius = ball_half.x;
	c.circle_blueprint.density = 1.f;
	c.circle_blueprint.friction = 1.f;
	c.circle_blueprint.restitution = 1.f;
	c.body_blueprint.position = b2Vec2_zero;
	sim.AddBluePrint("ball", c);

	ammo::Polygon p;
	p.polygon_blueprint.SetAsBox( world_half.x, 1.f );
	p.polygon_blueprint.density = 0.f;
	p.polygon_blueprint.friction  = 1.f;
	p.polygon_blueprint.restitution = 1.f;
	sim.AddBluePrint("long_wall", p );

	p.polygon_blueprint.SetAsBox( paddle_half.x, paddle_half.y );
	p.polygon_blueprint.density = 0.f;
	p.polygon_blueprint.friction  = 1.f;
	p.polygon_blueprint.restitution = 1.f;
	sim.AddBluePrint("paddle", p );

}

int main()
{
	ammo::PassivePhysicSys psim;
	ammo::ActivePhysicSys sim;

	physic_load( sim );
	// Defines PI
	const float PI = std::atan(1.0) * 4.0;

	ammo::Physic top_shape = sim.GetPhysic("long_wall",dummy);
	top_shape.SetPosition( b2Vec2(0.f, world_half.y ) );

	ammo::Physic bottom_shape = sim.GetPhysic("long_wall",dummy);
	bottom_shape.SetPosition( b2Vec2(0.f, -world_half.y ) );

	ammo::Physic ball_shape = sim.GetPhysic("ball",dummy);
	ammo::Physic left_shape = sim.GetPhysic("paddle",dummy);
	ammo::Physic right_shape = sim.GetPhysic("paddle",dummy);

	left_shape.SetPosition(	b2Vec2( -world_half.x + 3*paddle_half.x, 0.f ) );
	right_shape.SetPosition( b2Vec2( world_half.x - 3*paddle_half.x, 0.f ) );

	float speed = 30.f;
	float ai_speed = speed;
	float angle	= sf::Randomizer::Random( -PI * 0.25f, PI * 0.75f);
	if( angle > PI * 0.25 )
	{ angle += PI * 0.5;	}

	b2Vec2 ball_vel( speed*std::cos(angle), speed*std::sin(angle) );
	ball_shape.SetVelocity(ball_vel);

	ammo::ActiveSoundSys audio;
	ammo::PassiveSoundSys unused_audio;

	ammo::RandomDef random_def;
	random_def.m_filenames.push_back("data/Metalhit1.ogg");
	random_def.m_filenames.push_back("data/Metalhit2.ogg");
	random_def.m_filenames.push_back("data/Metalhit3.ogg");
	audio.AddBluePrint("bounce", random_def );

	audio.AddBluePrint("score", ammo::PlainDef("data/ball.wav") );

	ammo::Sound bounce = audio.getSound("bounce");
	ammo::Sound score = audio.getSound("score");

	// Create the window of the application
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "SFML Pong");

	ammo::View v(App);
	v.lookAt( b2Vec2_zero );
	v.setWidth( 2*world_half.x );

	ammo::ActiveGraphicSys graphics;
	ammo::PassiveGraphicSys unused_graphics;

	sim.EnableDebugDraw(graphics,100.f);

	ammo::SimpleAnimationDef anim_def;
	anim_def.addFrame( 0.1f, "data/noise1.png" );
	anim_def.addFrame( 0.1f, "data/noise2.png" );
	anim_def.addFrame( 0.1f, "data/noise3.png" );
	anim_def.addFrame( 0.1f, "data/noise4.png" );

	graphics.AddSchema("noise",anim_def);
	graphics.AddSchema("ball",ammo::SpriteDef("data/yinyang.png") );
	graphics.AddSchema("background",ammo::SpriteDef("data/background.jpg"));
	graphics.AddSchema("left_paddle",ammo::SpriteDef("data/blue_paddle.png"));
	graphics.AddSchema("right_paddle",ammo::SpriteDef("data/red_paddle.png"));

	ammo::Graphic background = graphics.NewGraphic("background");
	background.show();
	background.SetPosition( b2Vec2_zero );
	background.SetSize( 2*world_half );
	background.SetZOrder( -20.f );

	ammo::Graphic ball = graphics.NewGraphic("ball");
	ball.show();
	ball.SetSize( 2*ball_half );
	ball.SetZOrder(10.f);

	ammo::Graphic ball2 = graphics.NewGraphic("left_paddle");
	ball2.show();
	ball2.SetSize( 2*ball_half );
	ball2.SetZOrder(-10.f);

	ammo::Graphic left = graphics.NewGraphic("left_paddle");
	left.show();
	left.SetSize( 2*paddle_half );

	ammo::Graphic right = graphics.NewGraphic("right_paddle");
	right.show();
	right.SetSize( 2*paddle_half );

	ammo::Graphic noise = graphics.NewGraphic("noise");
	noise.show();
	noise.SetPosition( b2Vec2_zero );
	noise.SetSize( 0.5 * world_half );

	// Load the text font
	sf::Font Cheeseburger;
	if ( !Cheeseburger.LoadFromFile("data/cheeseburger.ttf") )
		return EXIT_FAILURE;

	// Initialize the end text
	sf::String End;
	End.SetFont(Cheeseburger);
	End.SetSize(5.f);
	End.Move( v.world2draw( b2Vec2( -world_half.x*0.5,0) ));
	End.SetColor(sf::Color(50, 50, 250));

	sf::Clock AITimer;
	const float AITime     = 0.1f;

	bool IsPlaying = true;
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
		}

		if ( IsPlaying )
		{
			sim.Update( App.GetFrameTime() );

			// Player logic
			if ( App.GetInput().IsKeyDown(sf::Key::Up)   && (left_shape.GetPosition().y + paddle_half.y < world_half.y) )
			{	
				left_shape.SetPosition( left_shape.GetPosition() + b2Vec2( 0.f, speed * App.GetFrameTime()) );
			}
	
			if ( App.GetInput().IsKeyDown(sf::Key::Down) && (left_shape.GetPosition().y - paddle_half.y > -world_half.y) )
			{	
				left_shape.SetPosition( left_shape.GetPosition() + b2Vec2( 0.f, -speed * App.GetFrameTime()) );
			}

			if( App.GetInput().IsKeyDown(sf::Key::Left) )
			{
				left.SetRotationDegrees( 1+left.GetRotationDegrees() );
			}
	
			if( App.GetInput().IsKeyDown(sf::Key::Right) )
			{
				left.SetRotationDegrees( left.GetRotationDegrees()-1 );
			}
	
			// AI logic
			right_shape.SetPosition( right_shape.GetPosition() + b2Vec2(0.f, ai_speed * App.GetFrameTime()) );

			// Update the computer's paddle direction according to the ball position
			if( AITimer.GetElapsedTime() > AITime )
			{
				AITimer.Reset();
				// paddle moving down and bottom of ball above top of paddle
				if( (ai_speed < 0) && ((ball_shape.GetPosition().y - ball_half.y) > (right_shape.GetPosition().y + paddle_half.y)) )
					{ ai_speed = speed * 0.5f; }

				// paddle moving up and top of ball below bottom of paddle
				if( (ai_speed > 0) && ((ball_shape.GetPosition().y + ball_half.y) < (right_shape.GetPosition().y - paddle_half.y)) )
					{ ai_speed = -speed * 0.5f; }
			}

			right_shape.SetPosition( right_shape.GetPosition() + b2Vec2( 0.f, ai_speed * App.GetFrameTime()) );

			b2Vec2 ball_pos = ball_shape.GetPosition();

			// Check collisions between the ball and the sides of the screen
			if( ball_pos.x - ball_half.x < -world_half.x )
			{
				IsPlaying = false;
				End.SetText("You lost !\n(press escape to exit)");
				score.play();
			}
			if( ball_pos.x + ball_half.x > world_half.x )
			{
				IsPlaying = false;
				End.SetText("You won !\n(press escape to exit)");
				score.play();
			}

			left.SetPosition( left_shape.GetPosition() );
			left.SetRotationRadians( left_shape.GetTheta() );
			right.SetPosition( right_shape.GetPosition() );
			right.SetRotationRadians( right_shape.GetTheta() );
			ball.SetPosition( ball_shape.GetPosition() );
			ball.SetRotationRadians( ball_shape.GetTheta() );

			// this looks pretty distubing but it shows how easy ammo::View makes it to 
			// have the screen track a given point.
			//v.lookAt(ball_pos);
		}

		audio.update( App.GetFrameTime() );
		graphics.Update( App.GetFrameTime() );

		// Clear the window
		App.Clear();

		graphics.Draw(App);

		// If the game is over, display the end message
		if ( !IsPlaying )
			{ App.Draw(End); }

		// Display things on screen
		App.Display();
	}

	return EXIT_SUCCESS;
}
