//
// Created by kshou on 2022/1/6.
//

#include "STGEngine.h"
#include "UI_common.h"
#include <iostream>
#include <cmath>
using namespace sf;


void STGEngine::handleInput()
{
    Event event{};

    // keep polling event
    while(window.pollEvent(event)) {

        // closing window (clicking on the X)
        if (event.type == Event::Closed) {
            std::cout << "Closing window" << std::endl;         // print log message to console
            window.close();
        }

        // handle keyboard input
        // quit
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            std::cout << "Closing window" << std::endl;     // print log message to console
            window.close();
        }

        // down key i.e. W
        if (Keyboard::isKeyPressed(Keyboard::W)) {
            std::cout << "KeyPressed: W" << std::endl;     // print log message to console
            player1.move(0.0f, -player_each_move_displacement);         // move up by 0.1 pixel
        }

        // down key i.e. A
        if (Keyboard::isKeyPressed(Keyboard::A)) {
            std::cout << "KeyPressed: A" << std::endl;     // print log message to console
            player1.move(-player_each_move_displacement, 0.0f);         // move left by 0.1 pixel
        }

        // down key i.e. S
        if (Keyboard::isKeyPressed(Keyboard::S)) {
            std::cout << "KeyPressed: S" << std::endl;     // print log message to console
            player1.move(0.0f, player_each_move_displacement);         // move down by 0.1 pixel
        }

        // down key i.e. D
        if (Keyboard::isKeyPressed(Keyboard::D)) {
            std::cout << "KeyPressed: D" << std::endl;     // print log message to console
            player1.move(player_each_move_displacement, 0.0f);         // move right by 0.1 pixel
        }

        // this is for holding mouseButton
        if (Mouse::isButtonPressed(Mouse::Left)){
            // shoot bullet from the position of the player
            // construct a bullet instance at the end of the vector
            // calculate the direction vector (normalized) with mouse pointing direction
            Vector2f direction((float)Mouse::getPosition(window).x - player1.getPosition().x, (float)Mouse::getPosition(window).y - player1.getPosition().y);
            // normalize the direction vector
            float norm = sqrt(pow(direction.x , 2) + pow(direction.y , 2));
            direction.x /= norm;
            direction.y /= norm;
            bulletList.emplace_back(&player1, direction);
        }

        // this is for single mouseButton click
        /*if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
            // shoot bullet from the position of the player
            // construct a bullet instance at the end of the vector
            bulletList.emplace_back(&player1);
            }
        }*/

    }
}