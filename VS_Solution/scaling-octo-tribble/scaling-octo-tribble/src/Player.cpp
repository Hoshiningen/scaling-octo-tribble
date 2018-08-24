#include "Player.h"

#include <numeric>

#include "GameManager.h"
#include "TextureManager.h"
#include "Weapon.h"

using namespace std::chrono_literals;

namespace
{
	constexpr size_t NUM_PROJECTILES = 20;
}

std::chrono::high_resolution_clock::time_point sot::Player::lastFiredTime = std::chrono::high_resolution_clock::now();

sot::Player::Player(sf::Vector2f o)
    : origin(o)
{
	initializeProjectiles();
}

void sot::Player::tick(const float deltaTime)
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
		fireProjectile();
	}

    // Machine gun
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
    {
        m_weapon.SetWeaponProperties(WeaponProperties{ 400.f, 100ms });
    }

    // Sniper
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
    {
        m_weapon.SetWeaponProperties(WeaponProperties{ 1000.f, 50ms });
    }
}

void sot::Player::fireProjectile()
{
    auto now = std::chrono::high_resolution_clock::now();

	if (!quiver.empty() && (now - lastFiredTime) >= m_weapon.GetProperties().GetFireDelay())
	{
        m_weapon.FireWeapon(getPosition(), quiver);

        // Update the timer to start the firing cool down
        lastFiredTime = std::chrono::high_resolution_clock::now();
	}
}

void sot::Player::initializeProjectiles()
{
	TextureManager& textManager = TextureManager::getSingleton();
	const sf::Texture& projectileTexture = textManager.getTexture(TextureID::PROJECTILE);

	for (int i = 0; i < NUM_PROJECTILES; ++i)
	{
		auto projectile = std::make_shared<Projectile>();

		projectile->setTexture(projectileTexture);
		projectile->setScale({0.125, 0.25f});

		//delete below, for testing
		projectile->setPosition(400, 400);

		quiver.emplace(projectile);
	}
}
