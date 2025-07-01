#pragma once
#include "SpriteGo.h"


class Axe : public SpriteGo
{
protected:
	sf::Vector2f offset;
	sf::Vector2f playerPos;
	bool isDraw = false;

public:
	Axe(const std::string& texId = "", const std::string& name = "");
	
	void Init() override;
	void SetPlayerPos(const sf::Vector2f& pos);
	void SetSide(Sides side);
	void SetIsDraw(bool b);

	void Draw(sf::RenderWindow& window) override;
};