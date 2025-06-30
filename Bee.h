#pragma once
#include "SpriteGo.h"


class Bee : public SpriteGo
{
protected:
	float startPosY = 0;

public:
	Bee(const std::string& texId = "", const std::string& name = "");

	float speed = 0.0f;
	sf::Vector2f direction;

	void SetSide(Sides side);

	void Reset() override;
	void Update(float dt) override;
};