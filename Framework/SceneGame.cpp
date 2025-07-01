#include "stdafx.h"
#include "SceneGame.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "BackgroundElement.h"
#include "Utils.h"
#include "Tree.h"
#include "Bee.h"
#include "Player.h"
#include "Axe.h"
#include "UiHud.h"


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
    texIds.push_back("graphics/axe.png");
    texIds.push_back("graphics/rip.png");

    fontIds.push_back("fonts/KOMIKAP_.ttf");

    // Objects
    AddGameObject(new SpriteGo("graphics/background.png"));
    
    for (int i = 0; i < 3; i++)
    {
        auto element = (BackgroundElement*)AddGameObject(new BackgroundElement("graphics/cloud.png")); // 구름
    }
    
    auto elementBee = (Bee*)AddGameObject(new Bee("graphics/bee.png")); // 벌 (동적 할당)

   
    tree = (Tree*)AddGameObject(new Tree());
    player = (Player*)AddGameObject(new Player());
    axe = (Axe*)AddGameObject(new Axe("graphics/axe.png"));
    
    uiHud = (UiHud*)AddGameObject(new UiHud());

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

    score = 0;
    uiHud->SetScore(score);

    timer = timerMax;
    uiHud->SetTimeBar(timer / timerMax);

    uiHud->SetMessage("PRESS ENTER TO START");
    uiHud->SetShowMessage(true);
}

void SceneGame::Exit()
{
    Scene::Exit();
}

void SceneGame::Update(float dt)
{
    Scene::Update(dt);

    if (InputMgr::GetKeyDown(sf::Keyboard::Return))
    {
        isPlaying = !isPlaying;
        player->Reset();
        uiHud->SetShowMessage(false);

        timer = timerMax;
        uiHud->SetTimeBar(timer / timerMax);
    }

    if (isPlaying)
    {
        FRAMEWORK.SetTimeScale(1.0f);
        timer -= dt;

        if (InputMgr::GetKeyDown(sf::Keyboard::Left))
        {
            axe->SetIsDraw(true);
            tree->UpdateBranches();
            player->SetSide(Sides::Left);
            axe->SetPlayerPos(player->GetPosition());
            axe->SetSide(Sides::Left);

            if (tree->GetSide() == player->GetSide())
            {
                isPlaying = false;
                player->Die();
                tree->SetLastBranch();
                axe->SetIsDraw(false);
                score = 0;
                uiHud->SetScore(score);

                uiHud->SetMessage("PRESS ENTER TO RESTART");
                uiHud->SetShowMessage(true);
            }
            else
            {
                score += 10;
                uiHud->SetScore(score);
            }
        }
        if (InputMgr::GetKeyDown(sf::Keyboard::Right))
        {
            axe->SetIsDraw(true);
            tree->UpdateBranches();
            player->SetSide(Sides::Right);
            axe->SetPlayerPos(player->GetPosition());
            axe->SetSide(Sides::Right);

            if (tree->GetSide() == player->GetSide())
            {
                isPlaying = false;
                player->Die();
                tree->SetLastBranch();
                axe->SetIsDraw(false);
                score = 0;
                uiHud->SetScore(score);

                uiHud->SetMessage("PRESS ENTER TO RESTART");
                uiHud->SetShowMessage(true);
            }
            else
            {
                score += 10;
                uiHud->SetScore(score);
            }
        }

        if (InputMgr::GetKeyUp(sf::Keyboard::Left) || InputMgr::GetKeyUp(sf::Keyboard::Right))
        {
            axe->SetIsDraw(false);
        }

        if (tree->GetSide() == player->GetSide())
        {
            isPlaying = false;
            player->Die();
            tree->SetLastBranch();
            axe->SetIsDraw(false);
        }

       

        if (timer <= 0.0f)
        {
            FRAMEWORK.SetTimeScale(0.0f);
            timer = 0.0f;
            isPlaying = false;
            player->Die();
            tree->SetLastBranch();
            axe->SetIsDraw(false);

            uiHud->SetMessage("PRESS ENTER TO RESTART");
            uiHud->SetShowMessage(false);
        }
        uiHud->SetTimeBar(timer / timerMax);
    }
    else
    {
        FRAMEWORK.SetTimeScale(0.0f);
        uiHud->SetMessage("PRESS ENTER TO RESTART");
        uiHud->SetShowMessage(true);
    }
}