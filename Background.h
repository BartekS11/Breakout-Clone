#pragma once

#include "Constants.h"
#include "Entity.h"

class Background : public Entity
{
private:
	static sf::Texture texture;

public:
	Background(float x, float y);

	void update() override;
	void draw(sf::RenderWindow& window) override;
};