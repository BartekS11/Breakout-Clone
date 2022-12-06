#include "Paddle.h"

sf::Texture Paddle::texture;

void Paddle::process_player_input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		if (getSprite().x >= 0)
		{
			velocity.x = -Constants::PADDLE_SPEED;
		}
		else
		{
			velocity.x = 0;
		}
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		if (getSprite().x < Constants::WINDOW_WIDTH)
		{
			velocity.x = Constants::PADDLE_SPEED;
		}
		else 
		{
			velocity.x = 0;
		}
	}
	else 
	{
		velocity.x = 0;
	}
}

Paddle::Paddle(float x, float y) : Moving_entity()
{
	texture.loadFromFile("graphics/paddle.png");
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
	velocity = {Constants::PADDLE_SPEED, 0.f};
	sprite.setOrigin(getCentre());
}

void Paddle::update()
{
	process_player_input();
	sprite.move(velocity);
}

void Paddle::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void Paddle::move_up() noexcept {}

void Paddle::move_left() noexcept
{
	velocity.x = -Constants::PADDLE_SPEED;
}

void Paddle::move_right() noexcept
{
	velocity.x = Constants::PADDLE_SPEED;
}