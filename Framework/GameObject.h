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

	Origins originPreset = Origins::TL;

public:
	GameObject(const std::string& name = "");
	virtual ~GameObject();

	// Get
	const std::string& GetName() { return name; }
	bool GetActive() const { return active; }
	sf::Vector2f GetPosition() const { return position; }
	sf::Vector2f GetScale() const { return scale; }
	float GetRotation() const { return rotation; }
	sf::Vector2f GetOrigin() const { return origin; }

	// Set
	void SetName(const std::string& n) { name = n; }
	virtual void SetActive(bool a) { active = a; }
	virtual void SetPosition(const sf::Vector2f& pos) { position = pos; }
	virtual void SetScale(const sf::Vector2f& s) { scale = s; }
	virtual void SetRotation(float rot) { rotation = rot; }
	virtual void SetOrigin(const sf::Vector2f& o) { origin = o; }
	virtual void SetOrigin(Origins preset) { originPreset = preset; }


	virtual void Init() = 0;    // �ʱ�ȭ
	virtual void Release() = 0; // ����
	virtual void Reset() = 0;   // �ʱ� ���·� �ǵ�����
	virtual void Update(float dt) = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;
};