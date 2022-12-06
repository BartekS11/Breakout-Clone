#include "Interactions.h"

bool is_interacting(const Entity& e1, const Entity& e2)
{
	auto box1 = e1.get_Bounding_Box();
	auto box2 = e2.get_Bounding_Box();
	return box1.intersects(box2);
}

void handle_collision(Ball& b, Paddle& p)
{
	if (is_interacting(p, b))
	{
		b.move_up();
		if (b.getSprite().x < p.getSprite().x)
		{
			b.move_left();
		}
		else
		{
			b.move_right();
		}
	}


}
