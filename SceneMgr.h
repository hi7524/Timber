#pragma once
#include "Singleton.h"

class SceneMgr : public Singleton<SceneMgr>
{
	friend class Singleton<SceneMgr>;

protected:
	SceneMgr() = default;
	~SceneMgr() = default;

	std::vector<Scene*> scenes; // Scene으로 하면 추상클래스일 뿐더러 자식 클래스의 크기가 다 다르기 때문에 주솟값으로 해줘야 함 
	// 생성자 말고는 다 초기화 해줘야 함. 안그러면 쓰레기값인채로 시작
	SceneIds startScene = SceneIds::Game;   // 시작시 열릴 화면
	SceneIds currentScene = SceneIds::None; // 현재 열려있을 화면
	SceneIds nextScene = SceneIds::None;    

public:
	void Init();    // 초기화 작업
	void Release(); // 동적할당 해제 작업

	Scene* GetCurrentScene() { return scenes[(int)currentScene]; }
	SceneIds GetCurrentSceneId() const { return currentScene; }
	void ChangeScene(SceneIds id); // 순회 중에 화면이 넘어가게 되면 여러 오류가 발생할 수 있기 때문에 지연해서 실행하는 것이 필요

	void Update(float dt);
	void Draw(sf::RenderWindow& window);
};

#define SCENE_MGR (SceneMgr::Instance())