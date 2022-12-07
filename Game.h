#pragma once

#include <memory>
#include <typeinfo>
#include <vector>

#include "Entity.h"
#include "Constants.h"
#include "Background.h"
#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"

using entity_vector = std::vector<std::shared_ptr<Entity>>;
using entity_alias_vector = std::vector<Entity*>;

class Entity_Manager
{
private:
	entity_vector all_entities;

	std::map<size_t, entity_alias_vector> grouped_entities;

public:
	template<typename T, typename... Args>
	T& create(Args&&... args) {
		static_assert(std::is_base_of<Entity, T>::value,
			R"("T" type parameter in create() must be derived from Entity)");

		auto ptr{ std::make_unique<T>(std::forward<Args>(args)...) };

		auto ptr_alias = ptr.get();

		auto hash = typeid(T).hash_code();

		grouped_entities[hash].emplace_back(ptr_alias);

		all_entities.emplace_back(std::move(ptr));

		return *ptr_alias;
	}

	void refresh();
	void clear();

	template <typename T>
	auto& get_all()
	{
		return grouped_entities[typeid(T).hash_code()];
	}

	template <typename T, typename Func>
	void apply_all(const Func& func)
	{
		auto& entity_group{get_all<T>()};
		for (auto ptr : entity_group)
		{
			func(*dynamic_cast<T*>(ptr));
		}
	}
	void update();
	void draw(sf::RenderWindow& window);
};

class Game
{
private:
	sf::RenderWindow game_window{ { Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT },
		"Breakout-Clone Game" };
	enum class game_state {paused, running};
	Entity_Manager manager;
	game_state state{ game_state::running };
	
public:
	Game();

	void reset();

	void run();

	void createBricksObjects();
};