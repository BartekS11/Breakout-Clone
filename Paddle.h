#pragma once
#include "Constants.h"
#include "Entity.h"

class Paddle : public Moving_entity
{
private:
	static sf::Texture texture;
	void process_player_input();
public:
	Paddle(float x, float y);

	void update() override;
	void draw(sf::RenderWindow& window) override;
	void move_up() noexcept override;
	void move_left() noexcept override;
	void move_right() noexcept override;
	void move_down() noexcept override;
};