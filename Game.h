#pragma once


#include "Constants.h"
#include "Background.h"
#include "Ball.h"
#include "Paddle.h"
#include "Interactions.h"
#include "Brick.h"

class Game
{
private:
	sf::RenderWindow game_window{ { Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT },
		"Breakout-Clone Game" };

	Background the_Background{ 0.f, 0.f };
	Ball the_Ball { Constants::WINDOW_WIDTH / 2.f, Constants::WINDOW_HEIGHT / 2.f};
	Paddle the_Paddle{ Constants::WINDOW_WIDTH / 2.f, Constants::WINDOW_HEIGHT - Constants::PADDLE_HEIGHT };
	std::vector<Brick> bricks;
	enum class game_state {paused, running};
	game_state state{ game_state::running };

public:
	Game();

	void reset();

	void run();
};