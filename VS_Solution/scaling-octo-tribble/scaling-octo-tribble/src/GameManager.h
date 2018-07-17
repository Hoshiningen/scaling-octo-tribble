#pragma once
#include <memory>
#include <vector>
#include <unordered_map>

#include <SFML/Graphics.hpp>

#include"Tribble.h"

class GameManager final 
{
private:
	sf::RenderWindow window;
	//sf::Sprite testSprite;

	//std::unordered_map<sf::Sprite*, sf::Sprite> tribles;
	std::vector<Tribble> tribles;

	void tick();
	void tickAll(float deltaTime);

	void io(float delta_time);

public:
	GameManager(int width, int height);

	~GameManager() = default;

	//deleted functions
	GameManager(const GameManager& copy) = delete;
	GameManager(GameManager&& move) = delete;
	GameManager& operator=(const GameManager& copy) = delete;
	GameManager& operator=(GameManager&& move) = delete;

public:
	//api
	void gameLoop();
	void addTrible();

private:
	bool shutdown = false;
};

