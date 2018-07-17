#pragma once

#include "Tribble.h"

#include <memory>

class TribbleBuilder
{
public:
    TribbleBuilder();

    TribbleBuilder& setPosition(const sf::Vector2f& position);
    TribbleBuilder& setScale(const sf::Vector2f& scale);
    TribbleBuilder& setTexture(const sf::Texture& texture);
    TribbleBuilder& setVelocity(const sf::Vector2f& velocity);

    std::unique_ptr<Tribble> create();

private:
    std::unique_ptr<Tribble> pTribble{};
};