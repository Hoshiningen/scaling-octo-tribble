#include "TribbleBuilder.h"

#include <memory>

sot::TribbleBuilder::TribbleBuilder()
    : pTribble(std::make_unique<Tribble>()) {}

sot::TribbleBuilder& sot::TribbleBuilder::setPosition(const sf::Vector2f& p)
{
    pTribble->setPosition(p.x, p.y);
    return *this;
}

sot::TribbleBuilder& sot::TribbleBuilder::setVelocity(const sf::Vector2f& velocity)
{
    pTribble->setVelocity(velocity);
    return *this;
}

sot::TribbleBuilder& sot::TribbleBuilder::setScale(const sf::Vector2f& s)
{
    pTribble->setScale(s.x, s.y);
    return *this;
}

sot::TribbleBuilder& sot::TribbleBuilder::setTexture(const sf::Texture& t)
{
    pTribble->setTexture(t);
    return *this;
}

std::unique_ptr<sot::Tribble> sot::TribbleBuilder::create()
{
    auto ret = std::move(pTribble);
    pTribble = std::make_unique<Tribble>();

    return ret;
}