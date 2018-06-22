#include <string>
#include "TextureManager.h"
#include <iostream>

TextureManager::TextureManager()
{
	load_texture("art/tribble.png", TextureID::TRIBBLE);
}

void TextureManager::load_texture(std::string path, TextureID assignId)
{
	if (textures.find(static_cast<char>(assignId)) != textures.end())
		throw std::runtime_error("fatal error - when loading texture: " + path + ", textureid already used");

	//create a texture using operator[]; we know there isn't a previous texture because no exception thrown
	auto& textureObj = textures[static_cast<char>(assignId)];
	if (!textureObj.loadFromFile(path))
		throw std::runtime_error("fatal error - failed to load:" + path);
}

const sf::Texture& TextureManager::getTexture(TextureID id)
{
	auto itr = textures.find(static_cast<char>(id));
	if (itr != textures.end())
	{
		return itr->second;
	}

	//texture usage should be an initialization task, so I'm throwing exceptions if things don't initialize correctly.
	throw std::runtime_error("fatal error - texture not loaded for id: " + static_cast<int>(id));
}

TextureManager& TextureManager::getSingleton()
{
	static TextureManager singleton;
	return singleton;
}

