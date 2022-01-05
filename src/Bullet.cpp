//
// Created by kshou on 2022/1/6.
//

#include "Bullet.h"
#include "UI_common.h"
using namespace sf;

Bullet::Bullet(sf::Shape* player, const sf::Vector2f& direction)
        : radius(4), display(radius), player(player)
{
    display.setOrigin(radius, radius);
    // the bullet initial position is the position of the player
    display.setPosition(player->getPosition());
    velocity = Vector2f(speed_of_bullet * direction.x, speed_of_bullet * direction.y);
}

sf::Vector2f Bullet::getVelocity() const
{
    return velocity;
}

sf::CircleShape Bullet::getDisplay() const
{
    return display;
}

void Bullet::updatePosition()
{
    display.move(velocity);
}


// copy constructor
Bullet::Bullet(const Bullet& that) = default;
