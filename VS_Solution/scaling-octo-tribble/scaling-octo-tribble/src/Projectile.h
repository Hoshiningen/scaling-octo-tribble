#pragma once
#include <set>
#include <SFML/Graphics.hpp>
#include <map>

class Projectile : public sf::Sprite
{
	static std::set<Projectile*> activeProjectiles;
	//static std::map<Projectile*, Projectile*> activeProjectiles;

public:
    Projectile() = default;
	Projectile(int x) {}
    virtual ~Projectile() = default;

    //Projectile(const Projectile&) = delete;
    //Projectile& operator=(const Projectile&) = delete;

    void setVelocity(const sf::Vector2f& velocity) noexcept;
    void tick(const float deltaTime);
	void activate();

	static const std::set<Projectile*>& GetActiveProjectiles();

private:
    sf::Vector2f velocity{};
	bool bIsActive;
};

