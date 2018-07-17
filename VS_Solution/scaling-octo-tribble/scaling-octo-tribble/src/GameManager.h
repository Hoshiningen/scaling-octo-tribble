#pragma once
#include <memory>
#include <map>

#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Tribble.h"

class GameManager final 
{
public:
	GameManager(int width, int height);
	~GameManager() = default;

	//deleted functions
	GameManager(const GameManager& copy) = delete;
	GameManager(GameManager&& move) = delete;
	GameManager& operator=(const GameManager& copy) = delete;
	GameManager& operator=(GameManager&& move) = delete;

	//api
	void gameLoop();
	void addTribble();

    void addTribble(float x, float y);

private:
    void tick();
    void tickAll(float deltaTime);

    void io(float delta_time);

private:
    using TribbleMap = std::map<std::unique_ptr<Tribble>, Tribble&>;

    bool shutdown{ false };
    sf::RenderWindow window;
    TribbleMap tribbles;

    std::unique_ptr<Player> player;
};

