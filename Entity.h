#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
protected:
	sf::Sprite sprite;

public:
	virtual void update() = 0;
	virtual void draw(sf::RenderWindow& window) = 0;

	sf::FloatRect get_Bounding_Box() const noexcept;
	sf::Vector2f getCentre() const noexcept;

	sf::Vector2f getSprite();

	virtual ~Entity() {}
};

class Moving_entity : public Entity
{
protected:
	sf::Vector2f velocity;

public:
	virtual void move_up() noexcept = 0;
	virtual void move_left() noexcept = 0;
	virtual void move_right() noexcept = 0;
};