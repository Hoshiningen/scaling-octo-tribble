#pragma once

#include <vector>
#include <stack>
#include <memory>

#include <SFML/Graphics.hpp>

#include "Projectile.h"
#include "Weapon.h"
#include "GameConstants.h"

BEGIN_GAME_NAMESPACE

class Player : public sf::Sprite
{
public:

    explicit Player(sf::Vector2f origin);

    // We don't want no copying yo
    Player(const Player&) = delete;
    Player(const Player&&) = delete;
    Player& operator=(const Player&) = delete;
    Player& operator=(const Player&&) = delete;

    virtual ~Player() = default;

    void tick(const float deltaTime);

private:

    void initializeProjectiles();
    void fireProjectile();

private:

    static std::chrono::high_resolution_clock::time_point lastFiredTime;

    Weapon m_weapon{ WeaponProperties{ 400.f, 100ms } };
    std::stack<std::shared_ptr<Projectile>> quiver{};

    float speed{ 1000 };
    sf::Vector2f origin{};
};

END_GAME_NAMESPACE