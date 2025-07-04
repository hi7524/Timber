#include "stdafx.h"
#include "Utils.h"


void Utils::Init()
{
	srand(time(NULL));
}

float Utils::RandomValue()
{
	return ((float)rand() / (float)RAND_MAX);
}

int Utils::RandomRange(int min, int maxExclude)
{
	return rand() % maxExclude  + min;
}

float Utils::RandomRange(float min, float max)
{
	return min + ((float)rand() / RAND_MAX) * (max - min);
}

sf::Vector2f Utils::SetOrigin(sf::Transformable& obj, Origins preset, const sf::FloatRect rect)
{
    sf::Vector2f newOrigin(rect.width, rect.height);
    newOrigin.x *= ((int)preset % 3) * 0.5f;
    newOrigin.y *= ((int)preset / 3) * 0.5f;
    obj.setOrigin(newOrigin);
    return newOrigin;
}

sf::Vector2f Utils::SetOrigin(sf::Shape& obj, Origins preset)
{
    return SetOrigin(obj, preset, obj.getLocalBounds());
}

sf::Vector2f Utils::SetOrigin(sf::Text& obj, Origins preset)
{
    return SetOrigin(obj, preset, obj.getLocalBounds());
}

sf::Vector2f Utils::SetOrigin(sf::Sprite& obj, Origins preset)
{
    return SetOrigin(obj, preset, obj.getLocalBounds());
}
