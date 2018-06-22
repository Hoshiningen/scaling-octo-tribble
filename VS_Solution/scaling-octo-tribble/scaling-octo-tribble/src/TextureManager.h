#pragma once
#include <unordered_map>
#include "SFML\Graphics\Texture.hpp"

enum class TextureID : char {
	TRIBBLE,
	PROJECTILE
};

class TextureManager final
{
	std::unordered_map<char, sf::Texture> textures;

public:
	const sf::Texture& getTexture(TextureID id);
	static TextureManager& getSingleton();

	~TextureManager() = default;
private:
	//deleted functions
	TextureManager();
	TextureManager(const TextureManager& copy) = delete;
	TextureManager(TextureManager&& move) = delete;
	TextureManager& operator=(const TextureManager& copy) = delete;
	TextureManager& operator=(TextureManager&& move) = delete;
	void load_texture(std::string path, TextureID assignId);
};