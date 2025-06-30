#include "stdafx.h"
#include "SceneGame.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "BackgroundElement.h"
#include "Utils.h"
#include "Tree.h"


SceneGame::SceneGame() : Scene(SceneIds::Game)
{
}

SceneGame::~SceneGame()
{
}

// 게임이 열리고 닫힘과 상관 없이 
void SceneGame::Init()
{
    texIds.push_back("graphics/background.png");
    texIds.push_back("graphics/cloud.png");
    texIds.push_back("graphics/tree.png");
    texIds.push_back("graphics/branch.png");

    // obj
    AddGameObject(new SpriteGo("graphics/background.png"));
    
    
    for (int i = 0; i < 3; i++)
    {
        auto element = (BackgroundElement*)AddGameObject(new BackgroundElement("graphics/cloud.png"));
    }

    AddGameObject(new Tree);

    Utils::Init();


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