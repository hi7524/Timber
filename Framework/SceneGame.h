#pragma once
#include "Scene.h"

// ���漱��
class Player;
class Tree; 

class SceneGame : public Scene
{
protected:
	Player* player;
	Tree* tree;

public:
	SceneGame();
	~SceneGame() override;

	void Enter() override;
	void Exit() override;
	void Update(float dt) override;

	void Init() override;
};