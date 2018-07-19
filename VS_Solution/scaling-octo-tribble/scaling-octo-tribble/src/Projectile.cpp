#include "Projectile.h"

void Projectile::setVelocity(const sf::Vector2f& v) noexcept
{
    velocity = v;
}

void Projectile::tick(const float deltaTime)
{
    //get position
    sf::Vector2f position = getPosition();

    //change it by velocity
    position += { deltaTime * velocity.x, deltaTime * velocity.y};

    //update sprite's position based on how velocity moved it
    setPosition(position);
}

