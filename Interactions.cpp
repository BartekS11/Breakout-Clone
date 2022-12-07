#include "Interactions.h"

bool is_interacting(const Entity& e1, const Entity& e2)
{
	auto box1 = e1.get_Bounding_Box();
	auto box2 = e2.get_Bounding_Box();
	return box1.intersects(box2);
}

void handle_collision(Ball& b, const Paddle& p)
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

void handle_collision(Ball& b, Brick& p)
{
	if (is_interacting(p, b))
	{
		p.weaken();
		if (p.is_too_weak())
		{
			p.destroy();
		}

		float left_overlap = b.right() - p.left();
		float right_overlap = p.right() - b.left();
		float top_overlap = b.bottom() - p.top();
		float bottom_overlap = p.bottom() - b.top();

		bool from_left = std::abs(left_overlap) < std::abs(right_overlap);
		bool from_top = std::abs(top_overlap) < std::abs(bottom_overlap);

		float min_x_overlap = from_left ? left_overlap : right_overlap;
		float min_y_overlap = from_top ? top_overlap : bottom_overlap;
		if (std::abs(min_x_overlap) < std::abs(min_y_overlap))
		{
			if(from_left)
			{
				b.move_left();
			}
			else
			{
				b.move_right();
			}
		}
		else
		{
			if (from_top)
			{
				b.move_up();
			}
			else 
			{
				b.move_down();
;			}
		}
	}
}
