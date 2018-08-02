#pragma once
#include <set>
#include <SFML/Graphics.hpp>
#include <map>
#include <stack>
#include <memory>
#include <chrono>

class Projectile : public sf::Sprite, public std::enable_shared_from_this<Projectile>
{
private: //private statics
	static std::set<std::shared_ptr<Projectile> >  activeProjectiles;

public:
    Projectile() = default;
	Projectile(int x) {}
    virtual ~Projectile() = default;

    //Projectile(const Projectile&) = delete;
    //Projectile& operator=(const Projectile&) = delete;

    void setDirection(const sf::Vector2f&normalizedDirection) noexcept;
    void tick(const float deltaTime);
	void activate(std::stack<std::shared_ptr<Projectile> >& containerForDeactivation);

	static const std::set<std::shared_ptr<Projectile> > GetActiveProjectiles();

	void setSpeed(float newSpeed);
private:
	float speed;
    sf::Vector2f velocity{};
	bool bIsActive;

	std::stack<std::shared_ptr<Projectile> >* deactivationContainer = nullptr;
	
};

