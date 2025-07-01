#pragma once
#include "Scene.h"

// 전방선언
class Player;
class Tree; 
class Axe;
class UiHud;

class SceneGame : public Scene
{
protected:
	Player* player;
	Tree* tree;
	Axe* axe;
	UiHud* uiHud;
	
	bool isPlaying = false;
	int score = 0;
	float timer = 0.0f;
	float timerMax = 5.0f;

public:
	SceneGame();
	~SceneGame() override;

	void Enter() override;
	void Exit() override;
	void Update(float dt) override;

	void Init() override;
};