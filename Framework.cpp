#include "stdafx.h"
#include "Framework.h"


void Framework::Init(int w, int h, const std::string& t)
{
	window.create(sf::VideoMode(w, h), t);

    // 리소스 로드
	TEXTURE_MGR.Load(texIds);
	FONT_MGR.Load(fontIds);
	SOUNDBUFFER_MGR.Load(soundIds);

	// Manager 초기화
	InputMgr::Init();
	SCENE_MGR.Init();
}

void Framework::Do()
{
    while (window.isOpen())
    {
        InputMgr::Clear();
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            InputMgr::UpdateEvent(event);
        }

        //while (isPlaying)
        {
            // 게임 시간 관리
            sf::Time dt = clock.restart();
            realDeltaTime = deltaTime = dt.asSeconds();
            deltaTime *= timeScale;
            time += deltaTime;
            realTime = realDeltaTime;

            //Update
            InputMgr::Update(deltaTime);
            SCENE_MGR.Update(deltaTime);

            //Draw
            window.clear();
            SCENE_MGR.Draw(window);

            window.display();
        }
    }
}

void Framework::Release()
{
	SCENE_MGR.Release();

	SOUNDBUFFER_MGR.Unload(soundIds);
	FONT_MGR.Unload(fontIds);
	TEXTURE_MGR.Unload(texIds);
}