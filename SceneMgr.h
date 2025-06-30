#pragma once
#include "Singleton.h"

class SceneMgr : public Singleton<SceneMgr>
{
	friend class Singleton<SceneMgr>;

protected:
	SceneMgr() = default;
	~SceneMgr() = default;

	std::vector<Scene*> scenes; // Scene���� �ϸ� �߻�Ŭ������ �Ӵ��� �ڽ� Ŭ������ ũ�Ⱑ �� �ٸ��� ������ �ּڰ����� ����� �� 
	// ������ ����� �� �ʱ�ȭ ����� ��. �ȱ׷��� �����Ⱚ��ä�� ����
	SceneIds startScene = SceneIds::Game;   // ���۽� ���� ȭ��
	SceneIds currentScene = SceneIds::None; // ���� �������� ȭ��
	SceneIds nextScene = SceneIds::None;    

public:
	void Init();    // �ʱ�ȭ �۾�
	void Release(); // �����Ҵ� ���� �۾�

	Scene* GetCurrentScene() { return scenes[(int)currentScene]; }
	SceneIds GetCurrentSceneId() const { return currentScene; }
	void ChangeScene(SceneIds id); // ��ȸ �߿� ȭ���� �Ѿ�� �Ǹ� ���� ������ �߻��� �� �ֱ� ������ �����ؼ� �����ϴ� ���� �ʿ�

	void Update(float dt);
	void Draw(sf::RenderWindow& window);
};

#define SCENE_MGR (SceneMgr::Instance())