#include "TribbleBuilder.h"

#include <memory>

TribbleBuilder::TribbleBuilder()
    : pTribble(std::make_unique<Tribble>()) {}

TribbleBuilder& TribbleBuilder::setPosition(const sf::Vector2f& p)
{
    pTribble->setPosition(p.x, p.y);
    return *this;
}

TribbleBuilder& TribbleBuilder::setVelocity(const sf::Vector2f& velocity)
{
    pTribble->setVelocity(velocity);
    return *this;
}

TribbleBuilder& TribbleBuilder::setScale(const sf::Vector2f& s)
{
    pTribble->setScale(s.x, s.y);
    return *this;
}

TribbleBuilder& TribbleBuilder::setTexture(const sf::Texture& t)
{
    pTribble->setTexture(t);
    return *this;
}

std::unique_ptr<Tribble> TribbleBuilder::create()
{
    auto ret = std::move(pTribble);
    pTribble = std::make_unique<Tribble>();

    return ret;
}