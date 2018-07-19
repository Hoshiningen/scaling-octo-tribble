#pragma once

#include <SFML/Graphics.hpp>

class Projectile : public sf::Sprite
{
public:
    Projectile() = default;
    virtual ~Projectile() = default;

    Projectile(const Projectile&) = delete;
    Projectile& operator=(const Projectile&) = delete;

    void setVelocity(const sf::Vector2f& velocity) noexcept;
    void tick(const float deltaTime);

private:
    sf::Vector2f velocity{};
};

