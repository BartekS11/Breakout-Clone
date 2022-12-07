#include "Brick.h"
#include "Game.h"

sf::Texture Brick::texture;

const sf::Color brick_colour_hit1{0, 255, 0, 80};
const sf::Color brick_colour_hit2{0, 255, 0, 170};
const sf::Color brick_colour_hit3{0, 255, 0, 255};

Brick::Brick(float x, float y) : Entity()
{
	texture.loadFromFile("graphics/brick01.png");
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
	sprite.setOrigin(getCentre());
}

void Brick::set_Strenght(int s) noexcept
{
	strenght = s;
}

void Brick::weaken() noexcept
{
	--strenght;
}

bool Brick::is_too_weak() const noexcept
{
	return strenght <= 0;
}

void Brick::update()
{
	if (strenght == 1)
	{
		sprite.setColor(brick_colour_hit1);
	}
	else if (strenght == 2)
	{
		sprite.setColor(brick_colour_hit2);
	}
	else
	{
		sprite.setColor(brick_colour_hit3);
	}
}

void Brick::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

//void Brick::createBricksObjects()
//{
//	for (auto i = 0; i < Constants::BRICK_COLUMNS; ++i)
//	{
//		for (auto j = 0; j < Constants::BRICK_ROWS; ++j)
//		{
//			float x = Constants::BRICK_OFFSET + (i + 1) * Constants::BRICK_WIDTH;
//			float y = (j + 1) * Constants::BRICK_HEIGHT;
//
//			Game::getManager().create<Brick>(x, y);
//		}
//	}
//}

void Brick::eraseBricksObjects(std::vector<Brick>& bricks)
{
	bricks.erase(std::remove_if(std::begin(bricks), std::end(bricks),
		[](const Brick& b) { return b.is_destroyed(); }),std::end(bricks));
}
