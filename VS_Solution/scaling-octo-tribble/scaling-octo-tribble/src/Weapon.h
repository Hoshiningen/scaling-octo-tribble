#pragma once

#include "Projectile.h"
#include "GameConstants.h"

#include <chrono>

BEGIN_GAME_NAMESPACE

using namespace std::chrono_literals;

class WeaponProperties
{
public:

    WeaponProperties() = default;
    WeaponProperties(float speed, std::chrono::milliseconds time)
        : m_projectileSpeed(speed), m_fireDelay(time)
    {}

    void SetFireDelay(std::chrono::milliseconds time);
    void SetProjectileSpeed(float speed) { m_projectileSpeed = speed; }

    std::chrono::milliseconds GetFireDelay() const { return m_fireDelay; }
    float GetProjectileSpeed() const { return m_projectileSpeed; }

private:

    float m_projectileSpeed{ 0 };
    std::chrono::milliseconds m_fireDelay{ 100ms };
};

class Weapon
{
public:

    Weapon() = default;

    explicit Weapon(WeaponProperties wepProperties)
        : m_wepProperties(wepProperties)
    {}

    template<typename T>
    void SetWeaponProperties(T&& wepProperties)
    {
        m_wepProperties = std::forward<T>(wepProperties);
    }

    WeaponProperties GetProperties() const { return m_wepProperties; }

    void FireWeapon(const sf::Vector2f& vecCurrentPos, std::stack<std::shared_ptr<sot::Projectile>>& stkQuiver);

private:

    WeaponProperties m_wepProperties{};
};

END_GAME_NAMESPACE