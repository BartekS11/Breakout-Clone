#include <algorithm>

#include "Game.h"
#include "Interactions.h"


void Entity_Manager::refresh() {

	for (auto& [type, alias_vector] : grouped_entities) 
	{
		alias_vector.erase(remove_if(begin(alias_vector), end(alias_vector),
			[](const auto& p) { return p->is_destroyed(); }
		),
			end(alias_vector));
	}
	all_entities.erase(remove_if(begin(all_entities), end(all_entities),
		[](const auto& p) { return p->is_destroyed(); }
	),
		end(all_entities));
}
void Entity_Manager::clear()
{
	grouped_entities.clear();
	all_entities.clear();
}

void Entity_Manager::update()
{
	for (auto& e : all_entities)
	{
		e->update();
	}
}

void Entity_Manager::draw(sf::RenderWindow& window)
{
	for (auto& e : all_entities)
	{
		e->draw(window);
	}
}

Game::Game()
{
	game_window.setFramerateLimit(60);
}

void Game::reset()
{
	state = game_state::paused;
	manager.clear();
	manager.create<Background>(0.f, 0.f);
	manager.create<Ball>(Constants::WINDOW_WIDTH / 2.f, Constants::WINDOW_HEIGHT / 2.f);
	manager.create<Paddle>(Constants::WINDOW_WIDTH / 2.f, Constants::WINDOW_HEIGHT - Constants::PADDLE_HEIGHT);

	createBricksObjects();
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
			manager.update();
			manager.apply_all<Ball>([this](auto& the_Ball) {
				manager.apply_all<Brick>([&the_Ball](auto& the_Brick) {
					handle_collision(the_Ball, the_Brick);
					});
				});

			manager.apply_all<Ball>([this](auto& the_Ball) {
				manager.apply_all<Paddle>([&the_Ball](auto& the_Paddle) {
					handle_collision(the_Ball, the_Paddle);
					});
				});
			manager.refresh();
		}
		manager.draw(game_window);
		game_window.display();
	}
}

void Game::createBricksObjects()
{
	for (auto i = 0; i < Constants::BRICK_COLUMNS; ++i)
	{
		for (auto j = 0; j < Constants::BRICK_ROWS; ++j)
		{
			float x = Constants::BRICK_OFFSET + (i + 1) * Constants::BRICK_WIDTH;
			float y = (j + 1) * Constants::BRICK_HEIGHT;

			manager.create<Brick>(x, y);
		}
	}
}