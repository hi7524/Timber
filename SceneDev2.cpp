#include "stdafx.h"
#include "SceneDev2.h"
#include "TextGo.h"

SceneDev2::SceneDev2()
	: Scene(SceneIds::Dev2)
{
}

void SceneDev2::Init()
{
	fontIds.push_back("fonts/KOMIKAP_.ttf");

	TextGo* go = new TextGo("fonts/KOMIKAP_.ttf");
	go->SetText("Dev 2");
	go->SetSize(30);
	go->SetColor(sf::Color::White);
	go->SetPosition({ 1920 / 2, 1080 / 2 });
	go->SetOrigin(Origins::MC);
	AddGameObject(go);

	Scene::Init();
}

void SceneDev2::Update(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		SCENE_MGR.ChangeScene(SceneIds::Dev1);
	}
}