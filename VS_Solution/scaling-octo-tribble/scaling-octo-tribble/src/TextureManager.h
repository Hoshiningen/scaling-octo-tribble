#pragma once

#include <unordered_map>

#include "SFML\Graphics\Texture.hpp"

#include "GameConstants.h"

BEGIN_GAME_NAMESPACE

enum class TextureID : char
{
	TRIBBLE,
    PLAYER,
	PROJECTILE
};

class TextureManager final
{
public:
	const sf::Texture& getTexture(TextureID id) const;
	static TextureManager& getSingleton();

	~TextureManager() = default;

	TextureManager(const TextureManager& copy) = delete;
	TextureManager(TextureManager&& move) = delete;
	TextureManager& operator=(const TextureManager& copy) = delete;
	TextureManager& operator=(TextureManager&& move) = delete;

private:

	TextureManager();

	void loadTexture(std::string path, TextureID assignId);

private:
    std::unordered_map<char, sf::Texture> textures{};
};

END_GAME_NAMESPACE