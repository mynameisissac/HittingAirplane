//
// Created by kshou on 2022/1/6.
//

#include "STGEngine.h"
#include "UI_common.h"
using namespace sf;

STGEngine::STGEngine()
    : player1(PLAYER_RADIUS)
{
    resolution = Vector2i(WINDOW_WIDTH, WINDOW_HEIGHT);
    window.create(VideoMode(resolution.x, resolution.y), "STG", Style::Close | Style::Titlebar);
    window.setFramerateLimit(60);

    // set the origin of the shape from top-left to the centre of the circle
    player1.setOrigin(player1.getRadius(), player1.getRadius());

}


void STGEngine::run()
{
    // main game loop
    while (window.isOpen()){
        handleInput();

        // update all bullets position before drawing
        for(Bullet& bullet : bulletList)
            bullet.updatePosition();

        draw();
    }

}

// draw and display the elements of the game
void STGEngine::draw()
{
    // two-buffering drawing
    window.draw(player1);
    // draw all existing bullets
    for(const Bullet& bullet : bulletList)
        window.draw(bullet.getDisplay());

    window.display();

    window.clear(Color::Black);
}
