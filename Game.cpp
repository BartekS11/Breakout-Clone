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
	font.loadFromFile("fonts/KOMIKAP_.ttf");
}

void Game::reset()
{
	lives = Constants::PLAYER_LIVES;
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
	TextHandler text_state(font, Constants::WINDOW_WIDTH / 2.f - 125.f, Constants::WINDOW_HEIGHT / 2.f - 100.f,
		sf::Color::White, 35, "Paused");
	TextHandler lives_state(font, Constants::WINDOW_WIDTH / 2.f - 90.f, Constants::WINDOW_HEIGHT / 2.f - 50.f,
		sf::Color::White, 35, "Lives: " + std::to_string(lives));
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
		if (state == game_state::paused)
		{
			manager.draw(game_window);
		}

		if (state != game_state::running)
		{
			switch (state)
			{
			case game_state::paused:
				text_state.updateString("	Paused	 ");
				break;
			case game_state::game_over:
				text_state.updateString("  Game Over!  ");
				break;
			case game_state::player_wins:
				text_state.updateString("Player Wins!");
				break;
			default:
				break;
			}
			game_window.draw(text_state.getsfText());
			game_window.draw(lives_state.getsfText());
		}
		else
		{
			if (manager.get_all<Ball>().empty())
			{
				manager.create<Ball>(Constants::WINDOW_WIDTH / 2.f, Constants::WINDOW_HEIGHT / 2.f);
				--lives;

				state = game_state::paused;
			}
			if (manager.get_all<Brick>().empty())
			{
				state = game_state::player_wins;
			}
			if (lives <= 0)
			{
				state = game_state::game_over;
			}
			lives_state.updateString("Lives: " + std::to_string(lives));
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
			manager.draw(game_window);
		}
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