#pragma once
#include "stdafx.h"
#include "SpriteGo.h"


class BackgroundElement : public SpriteGo
{
protected:


public:
	BackgroundElement(const std::string& texId = "", const std::string& name = "");
	// �����߿��� �����س��� ����
	// ������θ� get set �����ؼ� �����ϰ� �� ��

	float speed = 0.0f;
	sf::Vector2f direction;

	void SetSide(int side);

	void Reset() override;
	void Update(float dt) override;
};