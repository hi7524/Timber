#pragma once
#include "GameObject.h"


class Player : public GameObject
{
protected:
	sf::Sprite sprite;
	Sides side = Sides::Right;
	std::vector<sf::Vector2f> positions;
	std::vector<sf::Vector2f> scales;
	std::string texId;

public:
	Player(const std::string& name = "");
	~Player() override = default;

	void SetSide(Sides s);
	Sides GetSide() const { return side; }

	void SetPosition(const sf::Vector2f& pos) override;

	// GameObject를 통해 상속
	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};