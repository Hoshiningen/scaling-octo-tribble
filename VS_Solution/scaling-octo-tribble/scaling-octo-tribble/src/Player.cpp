#include "Player.h"
#include "GameManager.h"
#include "TextureManager.h"

namespace
{
	const size_t NUM_PROJECTILES = 20;
}

Player::Player(sf::Vector2f o)
    : origin(o) 
{
	initializeProjectiles();
}

void Player::tick(const float deltaTime)
{
    const float distanceThreshold = GameManager::getSingleton().getWidth() / 2.f;
    const float leftBoundary = -distanceThreshold + getOrigin().x;
    const float rightBoundary = distanceThreshold - getOrigin().x;
    sf::Vector2f distanceVector = getPosition() - origin;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {  
        if (distanceVector.x > leftBoundary)
            move({deltaTime * -speed, 0});
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if (distanceVector.x < rightBoundary)
            move({ deltaTime * speed, 0 });
    }
}

void Player::initializeProjectiles()
{
	TextureManager& textManager = TextureManager::getSingleton();
	const sf::Texture& projectileTexture = textManager.getTexture(TextureID::PROJECTILE);

	for (int i = 0; i < NUM_PROJECTILES; ++i)
	{
		projectiles.emplace_back();
		projectiles[i].setTexture(projectileTexture);
		projectiles[i].setScale({0.125, 0.25f});

		//delete below, for testing
		projectiles[i].setPosition(400, 400);
	}

	projectiles[0].activate();
}
