#include "stdafx.h"
#include "Bee.h"


Bee::Bee(const std::string& texId, const std::string& name)
	:SpriteGo(texId, name)
{
}

void Bee::SetSide(Sides side)
{
	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	startPosY = Utils::RandomRange(100.0f, 850.0f);

	switch (side)
	{
	case Sides::Left:
		direction = { 1.0f, 0.0f };
		SetScale({ -1.0f, 1.0f });
		SetPosition({ -150.0f, startPosY });
		break;

	case Sides::Right:
		direction = { -1.0f, 0.0f };
		SetScale({ 1.0f, 1.0f });
		SetPosition({ bounds.width + 150.0f, startPosY });
		break;
	}
}

void Bee::Reset()
{
	SpriteGo::Reset();

	SetOrigin(Origins::MC);
	SetSide((Sides)Utils::RandomRange(0, 2));
	speed = Utils::RandomRange(2, 6) * 50;
}

void Bee::Update(float dt)
{
	//auto pos = GetPosition();
	//pos += direction * speed * dt;
	//SetPosition(pos);

	auto pos = GetPosition();
	float rd = pos.x * 3.14f / 180;
	pos += direction * speed * dt;
	pos.y = (sin(rd) * 50) + startPosY;

	SetPosition(pos);

	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	if (pos.x < -200.0f || pos.x > bounds.width + 200)
	{
		Reset();
	}
}