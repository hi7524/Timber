#include "stdafx.h"
#include "Axe.h"


Axe::Axe(const std::string& texId, const std::string& name)
	:SpriteGo(texId, name)
{
	
}

void Axe::Init()
{
	offset = { 90, -85 };
}

void Axe::SetOffsetPosition(const sf::Vector2f& pos)
{
	SetPosition({ pos.x + offset.x, pos.y + offset.y });
}

void Axe::SetPlayerPos(const sf::Vector2f& pos)
{
	playerPos = pos;
}

void Axe::SetSide(Sides side)
{
	if (side == Sides::Left)
	{
		SetScale({ -1.0f, 1.0f });
		SetPosition({ playerPos.x - offset.x, playerPos.y + offset.y });
	}

	if (side == Sides::Right)
	{
		SetScale({ 1.0f, 1.0f });
		SetPosition({ playerPos.x + offset.x, playerPos.y + offset.y });
	}
}

void Axe::SetIsDraw(bool b)
{
	isDraw = b;
}

void Axe::Draw(sf::RenderWindow& window)
{
	if (isDraw)
	{
		window.draw(sprite);
	}
}