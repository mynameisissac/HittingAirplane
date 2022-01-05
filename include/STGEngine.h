//
// Created by kshou on 2022/1/6.
//

#ifndef STG_STGENGINE_H
#define STG_STGENGINE_H

#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include <vector>

// meaning of STG refer to : https://en.wikipedia.org/wiki/Shoot_%27em_up

class STGEngine {

    private:
        // window
        sf::Vector2i resolution;
        sf::RenderWindow window;

        // player
        sf::CircleShape player1;

        // a vector storing all existing bullet instances
        std::vector<Bullet> bulletList;

    public:
        STGEngine();

        void handleInput();
        void draw();

        void run();

};


#endif //STG_STGENGINE_H
