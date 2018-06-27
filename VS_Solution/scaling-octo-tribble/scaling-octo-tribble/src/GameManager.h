#pragma once
#include <memory>
#include <vector>
#include <unordered_map>

#include <SFML/Graphics.hpp>

class GameManager final 
{
private:
	sf::RenderWindow window;
	sf::Sprite testSprite;

	void tick();
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
};

