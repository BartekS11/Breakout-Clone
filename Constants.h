#pragma once

class Constants
{
public:
	static constexpr int WINDOW_WIDTH{ 520 };
	static constexpr int WINDOW_HEIGHT{ 450 };
	static constexpr float BALL_SPEED{ 5.0f };
	static constexpr float PADDLE_WIDTH{ 60.f };
	static constexpr float PADDLE_HEIGHT{ 20.f };
	static constexpr float PADDLE_SPEED{ 5.f };
	static constexpr float BRICK_WIDTH{ 43.f };
	static constexpr float BRICK_HEIGHT{ 20.f };
	static constexpr float BRICK_OFFSET{ BRICK_WIDTH / 2.f };
	static constexpr int BRICK_COLUMNS{ 10 };
	static constexpr int BRICK_ROWS{ 4 };
};
