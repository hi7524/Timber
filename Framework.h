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

	float time;
	float deltaTime;

	float realTime;
	float realDeltaTime;

public:
	float GetTimeScale() const { return timeScale; }
	void SetTimeScale(float scale) { timeScale = scale; }

	float GetTime() const { return time; }
	float GetDeltaTime() const { return deltaTime; }
	float GetRealTime() const { return realTime; }
	float GetRealDeltaTime() const { return realDeltaTime; }

	virtual void Init();
	virtual void Do(); // main ∑Á«¡
	virtual void Release();
};

#define FRAMEWORK (Framework::Instance())