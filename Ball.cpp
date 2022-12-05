#include "Ball.h"

sf::Texture Ball::texture;

Ball::Ball(float x, float y)
{
	texture.loadFromFile("graphics/ball.png");
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
	velocity = {Constants::BALL_SPEED, Constants::BALL_SPEED};
}

void Ball::update()
{
	sprite.move(velocity);
	if (getSprite().x < 0)
	{
		velocity.x = -velocity.x;
	}
	if (getSprite().x > Constants::WINDOW_WIDTH)
	{
		velocity.x = -velocity.x;
	}

	if (getSprite().y < 0)
	{
		velocity.y = -velocity.y;
	}
	if (getSprite().y > Constants::WINDOW_HEIGHT)
	{
		velocity.y = -velocity.y;
	}

}

void Ball::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}
