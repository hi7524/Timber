#pragma once
#include "Singleton.h"


class Framework : public Singleton<Framework>
{
	friend Singleton<Framework>;

protected:
	Framework() = default;
	~Framework() override = default;

	sf::RenderWindow window;

	sf::Clock clock;
	float timeScale = 1.0f;

	float time = 0.0f;
	float deltaTime = 0.0f;

	float realTime = 0.0f;
	float realDeltaTime = 0.0f;

	std::vector<std::string> texIds;
	std::vector<std::string> fontIds;
	std::vector<std::string> soundIds;

public:
	sf::RenderWindow& GetWindow() { return window; }

	sf::Vector2u GetWindowSize() const { return window.getSize(); }
	sf::Vector2f GetWindowSizeF() const { return (sf::Vector2f)window.getSize(); }
	sf::FloatRect GetWindowBounds() const
	{
		sf::Vector2f size = GetWindowSizeF();
		return sf::FloatRect(0.0f, 0.0f, size.x, size.y);
	}

	float GetTimeScale() const { return timeScale; }
	void SetTimeScale(float scale) { timeScale = scale; }
	void SetIsPlaying(bool b);

	float GetTime() const { return time; }
	float GetDeltaTime() const { return deltaTime; }
	float GetRealTime() const { return realTime; }
	float GetRealDeltaTime() const { return realDeltaTime; }

	virtual void Init(int w, int h, const std::string& t);
	virtual void Do(); // main ∑Á«¡
	virtual void Release();
};

#define FRAMEWORK (Framework::Instance())