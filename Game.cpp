#include "Game.h"
#include "Interactions.h"

Game::Game()
{
	Brick::createBricksObjects(bricks);
	game_window.setFramerateLimit(60);
}

void Game::reset()
{
	Brick::createBricksObjects(bricks);
}

void Game::run()
{
	bool pause_key_active{ false };

	while (game_window.isOpen())
	{
		game_window.clear(sf::Color::Black);

		sf::Event event;

		while (game_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				game_window.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				game_window.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
			{
				if (!pause_key_active)
				{
					if (state == game_state::paused)
					{
						state = game_state::running;
					}
					else
					{
						state = game_state::paused;
					}
					pause_key_active = true;
				}
				else
				{
					pause_key_active = false;
				}
			}
		}
		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
		{
			reset();
		}
		if (state != game_state::paused)
		{
			the_Background.update();
			the_Ball.update();
			the_Paddle.update();
			for (auto& b : bricks)
			{
				b.update();
			}
			handle_collision(the_Ball, the_Paddle);

			for (auto& b : bricks)
			{
				handle_collision(the_Ball, b);
			}

			Brick::eraseBricksObjects(bricks);

		}
		the_Background.draw(game_window);
		the_Ball.draw(game_window);
		the_Paddle.draw(game_window);
		for (auto b : bricks)
		{
			b.draw(game_window);
		}
		game_window.display();
	}
}