#include "Player.h"
#include "GameManager.h"

Player::Player(sf::Vector2f o)
    : origin(o) {}

void Player::tick(const float deltaTime)
{
    const float distanceThreshold = GameManager::getSingleton().getWidth() / 2;
    const float leftBoundary = -distanceThreshold + getOrigin().x;
    const float rightBoundary = distanceThreshold - getOrigin().x;
    sf::Vector2f distanceVector = getPosition() - origin;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {  
        if (distanceVector.x > leftBoundary)
            move({deltaTime * -speed, 0});
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if (distanceVector.x < rightBoundary)
            move({ deltaTime * speed, 0 });
    }
}
