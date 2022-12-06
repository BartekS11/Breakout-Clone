#pragma once
#include "Entity.h"
#include "Constants.h"

class Ball : public Moving_entity
{
	static sf::Texture texture;

public:
	Ball(float x, float y);

	void update() override;
	void draw(sf::RenderWindow& window) override;
	void move_up() noexcept override;
	void move_left() noexcept override;
	void move_right() noexcept override;
};