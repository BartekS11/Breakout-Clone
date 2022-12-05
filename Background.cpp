#include "Background.h"

sf::Texture Background::texture;

Background::Background(float x, float y) : Entity()
{
	texture.loadFromFile("graphics/background.jpg");
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
}

void Background::update()
{
}

void Background::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

