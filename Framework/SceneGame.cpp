#include "stdafx.h"
#include "SceneGame.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "BackgroundElement.h"
#include "Utils.h"
#include "Tree.h"
#include "Bee.h"
#include "Player.h"


SceneGame::SceneGame() : Scene(SceneIds::Game)
{
}

SceneGame::~SceneGame()
{
}

// 게임이 열리고 닫힘과 상관 없이 
void SceneGame::Init()
{
    // Textures
    texIds.push_back("graphics/background.png");
    texIds.push_back("graphics/cloud.png");
    texIds.push_back("graphics/tree.png");
    texIds.push_back("graphics/bee.png");
    texIds.push_back("graphics/branch.png");
    texIds.push_back("graphics/player.png");

    // Objects
    AddGameObject(new SpriteGo("graphics/background.png"));
    
    for (int i = 0; i < 3; i++)
    {
        auto element = (BackgroundElement*)AddGameObject(new BackgroundElement("graphics/cloud.png")); // 구름
    }
    
    auto elementBee = (Bee*)AddGameObject(new Bee("graphics/bee.png")); // 벌 (동적 할당)

   
    tree = (Tree*)AddGameObject(new Tree()); // 계속 만들어져 있을 오브젝트
    player = (Player*)AddGameObject(new Player());
    Utils::Init();
    // 순회하며 init 함수 호출
    Scene::Init();
}

void SceneGame::Enter()
{
    Scene::Enter();

    sf::Vector2f pos = tree->GetPosition();
    pos.y = 950.0f;
    player->SetPosition(pos);
}

void SceneGame::Exit()
{
    Scene::Exit();
}

void SceneGame::Update(float dt)
{
    Scene::Update(dt);

    if (InputMgr::GetKeyDown(sf::Keyboard::Left))
    {
        tree->UpdateBranches();
        player->SetSide(Sides::Left);
    }
    if (InputMgr::GetKeyDown(sf::Keyboard::Right))
    {
        tree->UpdateBranches();
        player->SetSide(Sides::Right);
    }

    if (tree->GetSide() == player->GetSide())
    {
        std::cout << "충돌" << std::endl;
    }
}

