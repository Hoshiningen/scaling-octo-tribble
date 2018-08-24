#pragma once

#include "Tribble.h"

#include <memory>

#include "GameConstants.h"

BEGIN_GAME_NAMESPACE

class TribbleBuilder
{
public:
    TribbleBuilder();

    TribbleBuilder& setPosition(const sf::Vector2f& position);
    TribbleBuilder& setScale(const sf::Vector2f& scale);
    TribbleBuilder& setTexture(const sf::Texture& texture);
    TribbleBuilder& setVelocity(const sf::Vector2f& velocity);

    std::unique_ptr<sot::Tribble> create();

private:
    std::unique_ptr<sot::Tribble> pTribble{};
};

END_GAME_NAMESPACE