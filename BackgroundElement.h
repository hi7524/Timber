#pragma once
#include "stdafx.h"
#include "SpriteGo.h"


class BackgroundElement : public SpriteGo
{
protected:


public:
	BackgroundElement(const std::string& texId = "", const std::string& name = "");
	// 수업중에만 노출해놓고 쓰기
	// 원래대로면 get set 구현해서 안전하게 할 것

	float speed = 0.0f;
	sf::Vector2f direction;

	void SetSide(int side);

	void Reset() override;
	void Update(float dt) override;
};