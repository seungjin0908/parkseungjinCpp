#pragma once
class GameObject;
class UI;
class Scene
{
protected:
	//_gameObjects[LayerType::Background] => vector<GameObject*>
	//_gameObjects[LayerType::Object] => vector<GameObject*>
	//_gameObjects[LayerType::Character] => vector<GameObject*>
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

	Vector2 ScreenPosToWorldPos(Vector2 screenPos) { return screenPos + _cameraPosition; }

public:
	Scene() {}
	virtual ~Scene() {}


};

