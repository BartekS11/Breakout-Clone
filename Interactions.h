#pragma once
#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"

bool is_interacting(const Entity& e1, const Entity& e2);

void handle_collision(Ball& b, const Paddle& p);

void handle_collision(Ball& b, Brick& p);