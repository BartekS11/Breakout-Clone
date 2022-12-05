#include <string>
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Background.h"
#include "Ball.h"

using namespace std::literals;

int main()
{
	Background the_Background(0.f, 0.f);
	Ball the_Ball(Constants::WINDOW_WIDTH / 2.f, Constants::WINDOW_HEIGHT / 2.f);

	sf::RenderWindow game_window({Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT},
		"Breakout Game"s);
	game_window.setFramerateLimit(60);

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
		}
		the_Background.update();
		the_Ball.update();

		the_Background.draw(game_window);
		the_Ball.draw(game_window);
		game_window.display();
	}
}
