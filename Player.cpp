#include "stdafx.h"
#include "Player.h"


Player::Player(const std::string& name)
	:GameObject(name)
{
}

void Player::SetSide(Sides s)
{
	side = s;
	sprite.setPosition(position + positions[(int)side]);
	sprite.setScale(scales[(int)side]);
}

void Player::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	sprite.setPosition(position + positions[(int)side]);
}

void Player::Init()
{
	texId = "graphics/player.png";

	positions.resize(2);
	positions[(int)Sides::Left] = { -300.0f, 1.0f };
	positions[(int)Sides::Right] = { 300.0f, 1.0f };

	scales.resize(2);
	scales[(int)Sides::Left] = { -1.0f, 1.0f };
	scales[(int)Sides::Right] = { 1.0f, 1.0f };
}

void Player::Release()
{
}

void Player::Reset()
{
	sprite.setTexture(TEXTURE_MGR.Get(texId));
	Utils::SetOrigin(sprite, Origins::BC);
	SetSide(Sides::Right);
}

void Player::Update(float dt)
{

}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}