#pragma once

#include "Constants.h"
#include "Entity.h"

class Brick : public Entity
{
private:
	static sf::Texture texture;
	int strenght{ Constants::BRICK_STRENGTH };

public:
	Brick(float x, float y);

	void set_Strenght(int s) noexcept;
	void weaken() noexcept;
	bool is_too_weak() const noexcept;
	void update() override;
	void draw(sf::RenderWindow& window) override;
	static void eraseBricksObjects(std::vector<Brick>& bricks);
};