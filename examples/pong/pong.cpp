#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include "ammo/graphics.hpp"
#include "ammo/audio.hpp"

int main()
{
	// Defines PI
	const float PI = 3.14159f;

	b2Vec2 world_half( 40.f, 30.f );
	b2Vec2 paddle_half( 1.f, 4.f );
	b2Vec2 right_pos( world_half.x - 3*paddle_half.x, 0.f );
	b2Vec2 left_pos( -world_half.x + 3*paddle_half.x, 0.f );
	b2Vec2 ball_half( 1.f, 1.f );
	b2Vec2 ball_pos = b2Vec2_zero;

	float speed = 30.f;
	float ai_speed = speed;
	float angle;
	do
	{
		// Make sure the ball initial angle is not too much vertical
		angle = sf::Randomizer::Random(0.f, 2 * PI);
	} while( std::abs(std::cos(angle)) < 0.7f );

	b2Vec2 ball_vel( speed*std::cos(angle), speed*std::sin(angle) );

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

	ammo::SimpleAnimationDef anim_def;
	anim_def.addFrame( 0.1f, "data/noise1.png" );
	anim_def.addFrame( 0.1f, "data/noise2.png" );
	anim_def.addFrame( 0.1f, "data/noise3.png" );
	anim_def.addFrame( 0.1f, "data/noise4.png" );

	graphics.AddBluePrint("noise",anim_def);
	graphics.AddBluePrint("ball",ammo::SpriteDef("data/ball.png") );
	graphics.AddBluePrint("background",ammo::SpriteDef("data/background.jpg"));
	graphics.AddBluePrint("left_paddle",ammo::SpriteDef("data/blue_paddle.png"));
	graphics.AddBluePrint("right_paddle",ammo::SpriteDef("data/red_paddle.png"));

	ammo::Graphic background = graphics.getGraphic("background");
	background.show();
	background.SetPosition( b2Vec2_zero );
	background.SetSize( 2*world_half );
	background.SetZOrder( -20.f );

	ammo::Graphic ball = graphics.getGraphic("ball");
	ball.show();
	ball.SetSize( 2*ball_half );
	ball.SetZOrder(10.f);

	ammo::Graphic ball2 = graphics.getGraphic("left_paddle");
	ball2.show();
	ball2.SetSize( 2*ball_half );
	ball2.SetZOrder(-10.f);

	ammo::Graphic left = graphics.getGraphic("left_paddle");
	left.show();
	left.SetSize( 2*paddle_half );

	ammo::Graphic right = graphics.getGraphic("right_paddle");
	right.show();
	right.SetSize( 2*paddle_half );

	ammo::Graphic noise = graphics.getGraphic("noise");
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
			// Player logic
			if ( App.GetInput().IsKeyDown(sf::Key::Up)   && (left_pos.y + paddle_half.y < world_half.y) )
			{	
				left_pos += b2Vec2(0.f, speed * App.GetFrameTime());
			}

			if ( App.GetInput().IsKeyDown(sf::Key::Down) && (left_pos.y - paddle_half.y > -world_half.y) )
			{	
				left_pos += b2Vec2(0.f, -speed * App.GetFrameTime());
			}

			// AI logic
			right_pos += b2Vec2( 0.f, ai_speed * App.GetFrameTime() );

			// Update the computer's paddle direction according to the ball position
			if ( AITimer.GetElapsedTime() > AITime )
			{
				AITimer.Reset();
				// paddle moving down and bottom of ball above top of paddle
				if ( (ai_speed < 0) && ((ball_pos.y - ball_half.y) > (right_pos.y + paddle_half.y)) )
					ai_speed = speed * 0.5f;

				// paddle moving up and top of ball below bottom of paddle
				if ( (ai_speed > 0) && ((ball_pos.y + ball_half.y) < (right_pos.y - paddle_half.y)) )
					ai_speed = -speed * 0.5f;
			}

			right_pos += b2Vec2( 0, ai_speed * App.GetFrameTime() );

			// Move the ball
			ball_pos += App.GetFrameTime() * ball_vel;

			// Check collisions between the ball and the sides of the screen
			if ( ball_pos.x - ball_half.x < -world_half.x )
			{
				IsPlaying = false;
				End.SetText("You lost !\n(press escape to exit)");
				score.play();
			}
			if ( ball_pos.x + ball_half.x > world_half.x )
			{
				IsPlaying = false;
				End.SetText("You won !\n(press escape to exit)");
				score.play();
			}

			// Check collisions between the ball and the top and bottom of the screen
			if ( ball_pos.y + ball_half.y > world_half.y )
			{
				bounce.play();
				ball_vel.y = -ball_vel.y;
				ball_pos.y = world_half.y - ball_half.y;
			}
			if ( ball_pos.y - ball_half.y < -world_half.y )
			{
				bounce.play();
				ball_vel.y = -ball_vel.y;
				ball_pos.y = -world_half.y + ball_half.y;
			}

			// Check the collisions between the ball and the paddles
			// Left Paddle
			if ( ball_pos.x - ball_half.x < left_pos.x + paddle_half.x && 
				  ball_pos.x + ball_half.x > left_pos.x - paddle_half.x &&
				  ball_pos.y + ball_half.y > left_pos.y - paddle_half.y &&
				  ball_pos.y - ball_half.y < left_pos.y + paddle_half.y )
			{
				bounce.play();
				ball_vel.x = -ball_vel.x;
				ball_pos.x = left_pos.x + paddle_half.x + ball_half.x;
			}

			// Right Paddle
			if ( ball_pos.x - ball_half.x < right_pos.x + paddle_half.x && 
				  ball_pos.x + ball_half.x > right_pos.x - paddle_half.x &&
				  ball_pos.y + ball_half.y > right_pos.y - paddle_half.y &&
				  ball_pos.y - ball_half.y < right_pos.y + paddle_half.y )
			{
				bounce.play();
				ball_vel.x = -ball_vel.x;
				ball_pos.x = right_pos.x - paddle_half.x - ball_half.x;
			}
			
			left.SetPosition( left_pos );
			right.SetPosition( right_pos );
			ball.SetPosition( ball_pos );
			ball2.SetPosition( ball_pos + ball_half );

			// this looks pretty distubing but it shows how easy ammo::View makes it to 
			// have the screen track a given point.
			//v.lookAt(ball_pos);
		}

		audio.update( App.GetFrameTime() );
		graphics.update( App.GetFrameTime() );

		// Clear the window
		App.Clear();

		graphics.draw(App);

		// If the game is over, display the end message
		if ( !IsPlaying )
			App.Draw(End);

		// Display things on screen
		App.Display();
	}

	return EXIT_SUCCESS;
}
