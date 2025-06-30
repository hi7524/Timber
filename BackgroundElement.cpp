#include "stdafx.h"
#include "BackgroundElement.h"
#include "Utils.h"


BackgroundElement::BackgroundElement(const std::string& texId, const std::string& name)
	:SpriteGo(texId, name)
{
}

void BackgroundElement::SetSide(int side)
{
	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	float scale = Utils::RandomValue();

	switch (side)
	{
	case (int)Sides::Left:
		direction = { 1.0f, 0.0f };
		SetScale({ scale * -1.0f, scale });
		SetPosition({ -150.0f, Utils::RandomRange(100.0f, 500.0f) });
		break;

	case (int)Sides::Right:
		direction = { -1.0f, 0.0f };
		SetScale({ scale, scale });
		SetPosition({ bounds.width + 150.0f, Utils::RandomRange(100.0f, 500.0f) });
		break;
	}
}

void BackgroundElement::Reset()
{
	SpriteGo::Reset();

	SetOrigin(Origins::MC);
	SetSide(Utils::RandomRange(1, 3));
	speed = Utils::RandomRange(2, 6) * 100;
}

void BackgroundElement::Update(float dt)
{
	auto pos = GetPosition();
	pos += direction * speed * dt;
	SetPosition(pos);

	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	if (pos.x < -200.0f || pos.x > bounds.width + 200)
	{
		Reset();
	}
}