#pragma once


class Utils
{
public:
	static void Init();

	static float RandomValue(); // 0.0f ~ 1.0f
	static int RandomRange(int min, int maxExclude); // 
	static float RandomRange(float min, float max); // 둘 다 포함

	static sf::Vector2f SetOrigin(sf::Transformable& obj, Origins preset, const sf::FloatRect bound);
	static sf::Vector2f SetOrigin(sf::Shape& obj, Origins preset);
	static sf::Vector2f SetOrigin(sf::Text& obj, Origins preset);
	static sf::Vector2f SetOrigin(sf::Sprite& obj, Origins preset);
};