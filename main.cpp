#include "stdafx.h"
#include "SceneGame.h"



int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "TIMBER");

    TEXTURE_MGR.Load({
        "graphics/player.png",
        "graphics/axe.png",
        "graphics/bee.png",
        "graphics/branch.png",
        "graphics/cloud.png",
        "graphics/log.png",
        "graphics/rip.png",
        "graphics/tree.png"
    });

    FONT_MGR.Load(
        "fonts/KOMIKAP_.ttf"
    );


    SceneGame sceneGame;
    sceneGame.Init();
    sceneGame.Enter();
    
    while (window.isOpen()) 
    {
        sf::Event event;

        InputMgr::Clear();

        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed) 
            {
                window.close();
            }

            InputMgr::UpdateEvent(event);
        }

        //Update
        InputMgr::Update(0.0f);
        sceneGame.Update(0.0f);

        //Draw
        window.clear();
        sceneGame.Draw(window);
        

        window.display();
    }

    sceneGame.Release();

    return 0;
}