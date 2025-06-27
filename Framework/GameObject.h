#pragma once


class GameObject
{
protected:
	std::string name;
	bool active;

	sf::Vector2f position;
	float rotation;
	sf::Vector2f scale;
	sf::Vector2f origin;

public:
	virtual void Init();    // 초기화
	virtual void Release(); // 삭제
	virtual void Reset();   // 초기 상태로 되돌리기

	virtual void Update(float dt);
	virtual void Draw();
};