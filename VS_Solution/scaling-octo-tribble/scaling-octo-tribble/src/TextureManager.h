#pragma once
#include <unordered_map>
#include "SFML\Graphics\Texture.hpp"

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

private:

	//deleted functions
	TextureManager(const TextureManager& copy) = delete;
	TextureManager(TextureManager&& move) = delete;
	TextureManager& operator=(const TextureManager& copy) = delete;
	TextureManager& operator=(TextureManager&& move) = delete;

    //methods
	TextureManager();
	void load_texture(std::string path, TextureID assignId);

private: //fields
    std::unordered_map<char, sf::Texture> textures{};
};