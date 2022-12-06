#include "Brick.h"

sf::Texture Brick::texture;

Brick::Brick(float x, float y) : Entity()
{
	texture.loadFromFile("graphics/brick01.png");
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
	sprite.setOrigin(getCentre());
}

void Brick::update()
{

}

void Brick::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void Brick::createBricksObjects(std::vector<Brick>& bricks)
{
	for (auto i = 0; i < Constants::BRICK_COLUMNS; ++i)
	{
		for (auto j = 0; j < Constants::BRICK_ROWS; ++j)
		{
			float x = Constants::BRICK_OFFSET + (i + 1) * Constants::BRICK_WIDTH;
			float y = (j + 1) * Constants::BRICK_HEIGHT;

			bricks.emplace_back(x, y);
		}
	}
}
