#pragma once
#include "Scene.h"

// 전방선언
class Player;
class Tree; 
class Axe;

class SceneGame : public Scene
{
protected:
	Player* player;
	Tree* tree;
	Axe* axe;
	bool isPlaying = true;

public:
	SceneGame();
	~SceneGame() override;

	void Enter() override;
	void Exit() override;
	void Update(float dt) override;

	void Init() override;
};