#include "stdafx.h"
#include "SpriteGo.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "TIMBER");

    ResourceMgr<sf::Texture>::Instance().Load({
            "graphics/player.png",
            "graphics/axe.png",
            "graphics/bee.png",
            "graphics/branch.png",
            "graphics/cloud.png",
            "graphics/log.png",
            "graphics/rip.png",
            "graphics/tree.png"
    });

    SpriteGo spriteGo("graphics/player.png");
    spriteGo.Init();
    spriteGo.Reset();
    
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
        spriteGo.Update(0.0f);

        //Draw
        window.clear();

        spriteGo.Draw(window);
        
        window.display();
    }

    spriteGo.Release();

    return 0;
}