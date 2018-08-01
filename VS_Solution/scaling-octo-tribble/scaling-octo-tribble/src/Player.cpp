#include "Player.h"
#include "GameManager.h"
#include "TextureManager.h"

namespace
{
	const size_t NUM_PROJECTILES = 2;
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

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		if (quiver.size() != 0)
		{
			auto projectile = quiver.top();
			sf::Vector2f currentPos = getPosition();

			projectile->setPosition(currentPos);
			sf::Vector2i mousePosition = GameManager::getSingleton().getMousePosition();
			sf::Vector2f mousePosFloat = { static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y) };

			sf::Vector2f newVelocity = mousePosFloat - currentPos;

			//TODO normalize vector and multiple by speed

			projectile->setVelocity(newVelocity);
			projectile->activate(quiver);
			quiver.pop();
		}
	}
}

void Player::initializeProjectiles()
{
	TextureManager& textManager = TextureManager::getSingleton();
	const sf::Texture& projectileTexture = textManager.getTexture(TextureID::PROJECTILE);

	for (int i = 0; i < NUM_PROJECTILES; ++i)
	{
		//projectiles.emplace_back();
		auto projectile = std::make_shared<Projectile>();

		projectile->setTexture(projectileTexture);
		projectile->setScale({0.125, 0.25f});

		//delete below, for testing
		projectile->setPosition(400, 400);

		quiver.emplace(projectile);
	}

}
