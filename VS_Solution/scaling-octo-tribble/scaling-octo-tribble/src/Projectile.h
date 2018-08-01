#pragma once
#include <set>
#include <SFML/Graphics.hpp>
#include <map>
#include <stack>
#include <memory>

class Projectile : public sf::Sprite, public std::enable_shared_from_this<Projectile>
{
	static std::set<std::shared_ptr<Projectile> >  activeProjectiles;
	//static std::map<Projectile*, Projectile*> activeProjectiles;

public:
    Projectile() = default;
	Projectile(int x) {}
    virtual ~Projectile() = default;

    //Projectile(const Projectile&) = delete;
    //Projectile& operator=(const Projectile&) = delete;

    void setVelocity(const sf::Vector2f& velocity) noexcept;
    void tick(const float deltaTime);
	void activate(std::stack<std::shared_ptr<Projectile> >& containerForDeactivation);

	static const std::set<std::shared_ptr<Projectile> >& GetActiveProjectiles();

private:
    sf::Vector2f velocity{};
	bool bIsActive;
};

