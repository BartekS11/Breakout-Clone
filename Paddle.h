#pragma once
#include "Constants.h"
#include "Entity.h"

class Paddle : public Moving_entity
{
	static sf::Texture texture;
	void process_player_input();
public:
	Paddle(float x, float y);

	void update() override;
	void draw(sf::RenderWindow& window) override;
};