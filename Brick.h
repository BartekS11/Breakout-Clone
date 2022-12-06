#pragma once

#include "Constants.h"
#include "Entity.h"

class Brick : public Entity
{
private:
	static sf::Texture texture;

public:
	Brick(float x, float y);
	void update() override;
	void draw(sf::RenderWindow& window) override;
	static void createBricksObjects(std::vector<Brick>& bricks);
};