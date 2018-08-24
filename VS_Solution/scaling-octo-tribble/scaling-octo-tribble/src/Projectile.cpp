#include "Projectile.h"

#include <iostream>
#include <stack>
#include <memory>

#include "GameManager.h"

std::set<std::shared_ptr<sot::Projectile>> sot::Projectile::activeProjectiles{};

void sot::Projectile::setDirection(const sf::Vector2f& normalizedDirection) noexcept
{
    velocity = normalizedDirection;
	velocity *= speed;
}

void sot::Projectile::tick(const float deltaTime)
{
    //get position
    sf::Vector2f position = getPosition();

    //change position by velocity
    position += { deltaTime * velocity.x, deltaTime * velocity.y};

    //update sprite's position based on how velocity moved it
    setPosition(position);

	GameManager& singleton = GameManager::getSingleton();
	const sf::RenderWindow& window = singleton.getWindow();
	sf::FloatRect viewport(window.getViewport(window.getView()));
	
	if (!viewport.intersects(this->getGlobalBounds()))
	{
		if (deactivationContainer)
		{
			deactivationContainer->push(shared_from_this());
		}
		deactivationContainer = nullptr;
		activeProjectiles.erase(shared_from_this());
	}
}

void sot::Projectile::activate(std::stack<std::shared_ptr<Projectile> >& containerForDeactivation) //TODO make sure safe since player may be deleted before this
{
	bIsActive = true;
	
	Projectile::activeProjectiles.insert(shared_from_this());

	this->deactivationContainer = &containerForDeactivation;
}

const std::set<std::shared_ptr<sot::Projectile>> sot::Projectile::GetActiveProjectiles()
{
	//this intentionally makes a copy to prevent removal while iterating.
	return activeProjectiles;
}

void sot::Projectile::setSpeed(float newSpeed)
{
	speed = newSpeed;
}

