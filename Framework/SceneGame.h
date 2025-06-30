#pragma once
#include "Scene.h"


class SceneGame : public Scene
{
protected:

public:
	SceneGame();
	~SceneGame() override;

	void Enter() override;
	void Exit() override;

	void Init() override;
};