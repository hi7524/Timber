#include "stdafx.h"
#include "SceneGame.h"
#include "SpriteGo.h"
#include "TextGo.h"


SceneGame::SceneGame()
	:Scene(SceneIds::Game)
{
}

SceneGame::~SceneGame()
{
}

void SceneGame::Init()
{
    SpriteGo* spriteGo = new SpriteGo("graphics/player.png");
    spriteGo->SetOrigin(Origins::MC);

    TextGo* testText = new TextGo("fonts/KOMIKAP_.ttf");
    testText->SetText("hello world");
    testText->SetOrigin(Origins::MC);

    sf::Vector2f vec = { 1920 / 2, 1080 / 2 };
    testText->SetPosition(vec);

    AddGameObject(spriteGo);
    AddGameObject(testText);

    // 순회하며 init 함수 호출
    Scene::Init();
}