#include "Projectile.h"
#include <iostream>

std::set<Projectile*> Projectile::activeProjectiles;
//std::map<Projectile*, Projectile*> Projectile::activeProjectiles;

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

void Projectile::activate()
{
	bIsActive = true;
	std::cout << activeProjectiles.size() << std::endl;
	//Projectile::activeProjectiles[this] = this;
	Projectile::activeProjectiles.insert(this);
}

const std::set<Projectile*>& Projectile::GetActiveProjectiles()
{
	return activeProjectiles;
}

