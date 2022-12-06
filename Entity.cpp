#include "Entity.h"

sf::FloatRect Entity::get_Bounding_Box() const noexcept
{
    return sprite.getGlobalBounds();
}

sf::Vector2f Entity::getCentre() const noexcept
{
    auto box = get_Bounding_Box();
    return {box.width / 2.f, box.height / 2.f};
}

sf::Vector2f Entity::getSprite() const noexcept
{
    return sprite.getPosition();
}

float Entity::left() const noexcept
{
    auto box = get_Bounding_Box();
    return getSprite().x - box.height / 2.f;
}

float Entity::right() const noexcept
{
    auto box = get_Bounding_Box();
    return getSprite().x + box.width / 2.f;
}

float Entity::top() const noexcept
{
    auto box = get_Bounding_Box();
    return getSprite().y - box.height / 2.f;
}

float Entity::bottom() const noexcept
{
    auto box = get_Bounding_Box();
    return getSprite().y + box.height / 2.f;
}

void Entity::destroy() noexcept
{
    destroyed = true;
}

bool Entity::is_destroyed() const noexcept
{
    return destroyed;
}
