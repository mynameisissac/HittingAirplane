//
// Created by kshou on 2022/1/6.
//

#ifndef STG_BULLET_H
#define STG_BULLET_H
#include <SFML/Graphics.hpp>

class Bullet {
    private:
        // size of each bullet
        float radius;
        sf::CircleShape display;
        // change in x position, change in y position per frame
        sf::Vector2f velocity;

        // the player that shoot this bullet
        sf::Shape* player;
    public:
        // constructors
        Bullet(sf::Shape* player, const sf::Vector2f& direction); // NOLINT(google-explicit-constructor)
        Bullet(const Bullet& that);
        // move the bullet
        void updatePosition();

        // accessors
        sf::CircleShape getDisplay() const;
        sf::Vector2f getVelocity() const;

};


#endif //STG_BULLET_H
