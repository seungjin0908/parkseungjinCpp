#pragma once
class GameObject;
class UI;
class Scene
{
protected:
	vector<GameObject*> _gameObjects[static_cast<int>(LayerType::End)];
	queue<GameObject*> _despawnObjectList;
	vector<UI*> _uis;

	Vector2 _cameraPosition;
	CenterRect _cameraArea = {};
public:

//==========================================
//	## 기본함수
//==========================================
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	void SpawnGameObject(GameObject* gameObject);
	void DespawnGameObject(GameObject* gameObject);

	GameObject* FindGameObject(string name);

public:
	void AddUI(UI* ui);
	void RemoveUI(UI* ui);

public:
	void SetCameraPos(Vector2 pos) { _cameraPosition = pos; }
	Vector2 GetCameraPos() { return _cameraPosition; }
	void SetCameraArea(CenterRect area) { _cameraArea = area; }
	CenterRect GetCameraArea() { return _cameraArea; }

public:
	Scene() {}
	virtual ~Scene() {}

};

