#pragma once

#include <memory>
#include <map>

#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Tribble.h"
#include "GameConstants.h"

BEGIN_GAME_NAMESPACE

class GameManager final 
{
public:

    static GameManager& getSingleton();
	~GameManager() = default;

	//api
	void gameLoop();

	void draw(sf::RenderWindow& window);

	void addTribble();
    void addTribble(float x, float y);

    const int getWidth() const noexcept;
    const int getHeight() const noexcept;

    bool handleCollision(sf::Sprite* tribble, sf::Sprite* projectile) const;

	sf::Vector2i getMousePosition();
	const sf::RenderWindow& getWindow() const;

    /*
        Shoot the projectile

        The tribble needs to be aware that it was shot, and it needs
            to be able to die

        Collision can be done through sfml

        THe player registers "Active" projectiles with the game manager
        and collision could occur through it

        for (auto& projectile : Projectile::ACtiveProjectiles())
        {
            for (auto& tribble : tribbles)
            {
                if (projectile.collide(tribble))
                {
                    //  Hurray we have a collision
                }
            }
        }
    */

private:

    void tick();
    void tickAll(float deltaTime);
    void io(float delta_time);

    GameManager();
	
private:
    using TribbleMap = std::map<std::unique_ptr<Tribble>, Tribble&>;

    bool shutdown{ false };
    sf::RenderWindow window;
    TribbleMap tribbles{};

    std::unique_ptr<Player> player;
};

END_GAME_NAMESPACE