#include "stdafx.h"
#include "SceneDev1.h"
#include "TextGo.h"


SceneDev1::SceneDev1() : Scene(SceneIds::Dev1)
{
}

void SceneDev1::Init()
{
	fontIds.push_back("fonts/KOMIKAP_.ttf");

	TextGo* go = new TextGo("fonts/KOMIKAP_.ttf");
	go->SetText("Dev 1");
	go->SetSize(30);
	go->SetColor(sf::Color::White);
	go->SetPosition({ 1920/2, 1080/2 });
	go->SetOrigin(Origins::MC);
	AddGameObject(go);

	Scene::Init();
}

void SceneDev1::Update(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		SCENE_MGR.ChangeScene(SceneIds::Dev2);
	}
}