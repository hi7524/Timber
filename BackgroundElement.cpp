#include "stdafx.h"
#include "BackgroundElement.h"
#include "Utils.h"
#include "Bee.h"


BackgroundElement::BackgroundElement(const std::string& texId, const std::string& name)
	:SpriteGo(texId, name)
{
}

void BackgroundElement::SetSide(Sides side)
{
	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	float scale = Utils::RandomRange(0.5f, 1.0f);

	switch (side)
	{
	case Sides::Left:
		direction = { 1.0f, 0.0f };
		SetScale({ -scale, scale });
		SetPosition({ -150.0f, Utils::RandomRange(100.0f, 500.0f) });
		break;

	case Sides::Right:
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
	SetSide((Sides)Utils::RandomRange(0, 2));
	speed = Utils::RandomRange(2, 6) * 50;
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