#include "Weapon.h"

#include "Player.h"
#include "GameManager.h"

void sot::WeaponProperties::SetFireDelay(std::chrono::milliseconds time)
{
    m_fireDelay = std::move(time);
}

void sot::Weapon::FireWeapon(const sf::Vector2f& vecCurrentPos, std::stack<std::shared_ptr<sot::Projectile>>& stkQuiver)
{
    auto projectile = stkQuiver.top();

    projectile->setPosition(vecCurrentPos);
    sf::Vector2i mousePosition = GameManager::getSingleton().getMousePosition();
    sf::Vector2f mousePosFloat = { static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y) };
    sf::Vector2f newDirection = mousePosFloat - vecCurrentPos;

    // Normalize vector and multiple by speed
    float magnitude = std::sqrt(newDirection.x * newDirection.x + newDirection.y * newDirection.y);
    newDirection /= magnitude;

    projectile->setSpeed(m_wepProperties.GetProjectileSpeed());
    projectile->setDirection(newDirection);

    projectile->activate(stkQuiver);
    stkQuiver.pop();
}
