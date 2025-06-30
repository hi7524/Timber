#include "stdafx.h"
#include "SceneGame.h"
#include "SpriteGo.h"
#include "TextGo.h"


SceneGame::SceneGame() : Scene(SceneIds::Game)
{
}

SceneGame::~SceneGame()
{
}

// 게임이 열리고 닫힘과 상관 없이 
void SceneGame::Init()
{
    texIds.push_back("graphics/player.png");
    fontIds.push_back("fonts/KOMIKAP_.ttf");
    

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

void SceneGame::Enter()
{
    Scene::Enter();
}

void SceneGame::Exit()
{
    Scene::Exit();
}