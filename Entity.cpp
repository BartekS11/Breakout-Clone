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

sf::Vector2f Entity::getSprite()
{
    return sprite.getPosition();
}
