
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include "ammo/graphics.hpp"
#include "ammo/audio.hpp"


////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////
int main()
{
   //ammo::SoundSys audio;

   //audio.addDef("bounce", ammo::PlainDef("data/ball.wav") );
   ammo::Sound bounce;// = audio.getSound("bounce");

	// Defines PI
	const float PI = 3.14159f;

    // Create the window of the application
    sf::RenderWindow App(sf::VideoMode(800, 600, 32), "SFML Pong");

    ammo::GraphicSys graphics;

    ammo::SimpleAnimationDef anim_def;
    anim_def.addFrame( 0.3, "data/noise1.png" );
    anim_def.addFrame( 0.3, "data/noise2.png" );
    anim_def.addFrame( 0.3, "data/noise3.png" );
    anim_def.addFrame( 0.3, "data/noise4.png" );

    graphics.addDef("noise",anim_def);
    graphics.addDef("ball",ammo::SpriteDef("data/ball.png") );
    graphics.addDef("background",ammo::SpriteDef("data/background.jpg"));

    ammo::Graphic noise = graphics.getGraphic("noise");
    noise.show();
    noise.SetPosition( b2Vec2(400,50) );
    //noise.Move( b2Vec2(0,-100) );

    ammo::Graphic ball = graphics.getGraphic("ball");
    ball.show();

    ammo::Graphic background;// = graphics.getGraphic("background");
    background.show();
    background.SetPosition( b2Vec2(400,-300) );


    // Load the images used in the game
    sf::Image BackgroundImage, LeftPaddleImage, RightPaddleImage, BallImage;
    if (!BackgroundImage.LoadFromFile("data/background.jpg")    ||
        !LeftPaddleImage.LoadFromFile("data/paddle_left.png")   ||
        !RightPaddleImage.LoadFromFile("data/paddle_right.png") ||
        !BallImage.LoadFromFile("data/ball.png"))
    {
        return EXIT_FAILURE;
    }

    // Load the text font
    sf::Font Cheeseburger;
    if (!Cheeseburger.LoadFromFile("data/cheeseburger.ttf"))
        return EXIT_FAILURE;

	// Initialize the end text
	sf::String End;
    End.SetFont(Cheeseburger);
	End.SetSize(60.f);
    End.Move(150.f, 200.f);
    End.SetColor(sf::Color(50, 50, 250));

    // Create the sprites of the background, the paddles and the ball
    sf::Sprite Background(BackgroundImage);
    sf::Sprite LeftPaddle(LeftPaddleImage);
    sf::Sprite RightPaddle(RightPaddleImage);
    sf::Sprite Ball(BallImage);

    LeftPaddle.Move(10, (App.GetView().GetRect().GetHeight() - LeftPaddle.GetSize().y) / 2);
    RightPaddle.Move(App.GetView().GetRect().GetWidth() - RightPaddle.GetSize().x - 10, (App.GetView().GetRect().GetHeight() - RightPaddle.GetSize().y) / 2);
    Ball.Move((App.GetView().GetRect().GetWidth() - Ball.GetSize().x) / 2, (App.GetView().GetRect().GetHeight() - Ball.GetSize().y) / 2);

    // Define the paddles properties
    sf::Clock AITimer;
	const float AITime     = 0.1f;
    float LeftPaddleSpeed  = 400.f;
    float RightPaddleSpeed = 400.f;

    // Define the ball properties
    float BallSpeed = 400.f;
    float BallAngle;
    do
    {
        // Make sure the ball initial angle is not too much vertical
        BallAngle = sf::Randomizer::Random(0.f, 2 * PI);
    } while (std::abs(std::cos(BallAngle)) < 0.7f);

	bool IsPlaying = true;
    while (App.IsOpened())
    {
        // Handle events
        sf::Event Event;
        while (App.GetEvent(Event))
        {
            // Window closed or escape key pressed : exit
            if ((Event.Type == sf::Event::Closed) || 
               ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape)))
            {
                App.Close();
                break;
            }
        }

        if (IsPlaying)
		{
			// Move the player's paddle
            if (App.GetInput().IsKeyDown(sf::Key::Up) && (LeftPaddle.GetPosition().y > 5.f))
				LeftPaddle.Move(0.f, -LeftPaddleSpeed * App.GetFrameTime());
            if (App.GetInput().IsKeyDown(sf::Key::Down) && (LeftPaddle.GetPosition().y < App.GetView().GetRect().GetHeight() - LeftPaddle.GetSize().y - 5.f))
				LeftPaddle.Move(0.f, LeftPaddleSpeed * App.GetFrameTime());

			// Move the computer's paddle
            if (((RightPaddleSpeed < 0.f) && (RightPaddle.GetPosition().y > 5.f)) ||
                ((RightPaddleSpeed > 0.f) && (RightPaddle.GetPosition().y < App.GetView().GetRect().GetHeight() - RightPaddle.GetSize().y - 5.f)))
            {
                RightPaddle.Move(0.f, RightPaddleSpeed * App.GetFrameTime());
            }

            // Update the computer's paddle direction according to the ball position
            if (AITimer.GetElapsedTime() > AITime)
            {
                AITimer.Reset();
                if ((RightPaddleSpeed < 0) && (Ball.GetPosition().y + Ball.GetSize().y > RightPaddle.GetPosition().y + RightPaddle.GetSize().y))
                    RightPaddleSpeed = -RightPaddleSpeed;
                if ((RightPaddleSpeed > 0) && (Ball.GetPosition().y < RightPaddle.GetPosition().y))
                    RightPaddleSpeed = -RightPaddleSpeed;
            }

			// Move the ball
			float Factor = BallSpeed * App.GetFrameTime();
            Ball.Move(std::cos(BallAngle) * Factor, std::sin(BallAngle) * Factor);

			// Check collisions between the ball and the screen
			if (Ball.GetPosition().x < 0.f)
			{
				IsPlaying = false;
				End.SetText("You lost !\n(press escape to exit)");
			}
			if (Ball.GetPosition().x + Ball.GetSize().x > App.GetView().GetRect().GetWidth())
			{
				IsPlaying = false;
				End.SetText("You won !\n(press escape to exit)");
			}
			if (Ball.GetPosition().y < 0.f)
			{
   			    //audio.getSound("bounce").play(); 
				BallAngle = -BallAngle;
				Ball.SetY(0.1f);
			}
			if (Ball.GetPosition().y + Ball.GetSize().y > App.GetView().GetRect().GetHeight())
			{
   			    //audio.getSound("bounce").play(); 
				BallAngle = -BallAngle;
				Ball.SetY(App.GetView().GetRect().GetHeight() - Ball.GetSize().y - 0.1f);
			}

			// Check the collisions between the ball and the paddles
			// Left Paddle
			if (Ball.GetPosition().x < LeftPaddle.GetPosition().x + LeftPaddle.GetSize().x && 
				Ball.GetPosition().x > LeftPaddle.GetPosition().x + (LeftPaddle.GetSize().x / 2.0f) &&
				Ball.GetPosition().y + Ball.GetSize().y >= LeftPaddle.GetPosition().y &&
				Ball.GetPosition().y <= LeftPaddle.GetPosition().y + LeftPaddle.GetSize().y)
			{
				//BallSound.Play();
				//audio.getSound("bounce").play();
				bounce.play();
				BallAngle = PI - BallAngle;
				Ball.SetX(LeftPaddle.GetPosition().x + LeftPaddle.GetSize().x + 0.1f);
			}

			// Right Paddle
			if (Ball.GetPosition().x + Ball.GetSize().x > RightPaddle.GetPosition().x &&
				Ball.GetPosition().x + Ball.GetSize().x < RightPaddle.GetPosition().x + (RightPaddle.GetSize().x / 2.0f) &&
				Ball.GetPosition().y + Ball.GetSize().y >= RightPaddle.GetPosition().y &&
				Ball.GetPosition().y <= RightPaddle.GetPosition().y + RightPaddle.GetSize().y)
			{
				bounce.play();
				BallAngle = PI - BallAngle;
				Ball.SetX(RightPaddle.GetPosition().x - Ball.GetSize().x - 0.1f);
			}
		}

        //audio.update( App.GetFrameTime() );
        graphics.update( App.GetFrameTime() );

        ball.SetPosition( b2Vec2( Ball.GetPosition().x, -Ball.GetPosition().y ) );

        // Clear the window
        App.Clear();

        graphics.draw(App);

        // Draw the background, paddles and ball sprites
        //App.Draw(Background);
        App.Draw(LeftPaddle);
        App.Draw(RightPaddle);
        App.Draw(Ball);

        // If the game is over, display the end message
        if (!IsPlaying)
            App.Draw(End);

        // Display things on screen
        App.Display();
    }

    return EXIT_SUCCESS;
}
