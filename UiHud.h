#pragma once
#include "GameObject.h"


class UiHud : public GameObject
{
protected:
	sf::Text textScore;
	sf::Text textMessage;
	sf::RectangleShape timeBar;

	std::string fontId;
	bool isShowMessage = true;

	sf::Vector2f timeBarSize;

public:
	UiHud(const std::string& name = "");
	~UiHud() override = default;

	void SetScore(int score);
	void SetMessage(const std::string& msg);
	void SetShowMessage(bool show) { isShowMessage = show; }
	void SetTimeBar(float value); // 0.0f ~ 1.0f

	// GameObject을(를) 통해 상속됨
	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};