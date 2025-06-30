#include "stdafx.h"
#include "SceneGame.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "BackgroundElement.h"
#include "Utils.h"


SceneGame::SceneGame() : Scene(SceneIds::Game)
{
}

SceneGame::~SceneGame()
{
}

// ������ ������ ������ ��� ���� 
void SceneGame::Init()
{
    // ���� obj
    texIds.push_back("graphics/background.png");
    texIds.push_back("graphics/cloud.png");

    // obj
    AddGameObject(new SpriteGo("graphics/background.png"));
    
    auto element = (BackgroundElement*)AddGameObject(new BackgroundElement("graphics/cloud.png"));
    element->speed = 100.f;
    element->direction = { 1.f, 0.f };

    Utils::Init();
    std::cout << Utils::RandomValue() << std::endl;
    std::cout << Utils::RandomRange(1, 5) << std::endl;
    std::cout << Utils::RandomRange(1.0f, 5.0f) << std::endl;

    // ��ȸ�ϸ� init �Լ� ȣ��
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