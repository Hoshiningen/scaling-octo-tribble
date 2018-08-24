#pragma once

#include <set>
#include <map>
#include <stack>
#include <memory>
#include <chrono>

#include <SFML/Graphics.hpp>

#include "GameConstants.h"

BEGIN_GAME_NAMESPACE

class Projectile : public sf::Sprite, public std::enable_shared_from_this<Projectile>
{
public:
	static const std::set<std::shared_ptr<Projectile>> GetActiveProjectiles();

    Projectile() = default;
	Projectile(int x) {}

    virtual ~Projectile() = default;

    Projectile(const Projectile&) = delete;
    Projectile& operator=(const Projectile&) = delete;

    void setDirection(const sf::Vector2f&normalizedDirection) noexcept;
    void tick(const float deltaTime);
	void activate(std::stack<std::shared_ptr<Projectile> >& containerForDeactivation);
	void setSpeed(float newSpeed);

private: //private statics
	static std::set<std::shared_ptr<Projectile> >  activeProjectiles;

	float speed;
    sf::Vector2f velocity{};
	bool bIsActive;

	std::stack<std::shared_ptr<Projectile> >* deactivationContainer = nullptr;
	
};

END_GAME_NAMESPACE
