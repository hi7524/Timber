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
	virtual void Init();    // �ʱ�ȭ
	virtual void Release(); // ����
	virtual void Reset();   // �ʱ� ���·� �ǵ�����

	virtual void Update(float dt);
	virtual void Draw();
};