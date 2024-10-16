#pragma once
class GameObject;
class Scene
{

	//==========================================
	//	## 기본함수
	//==========================================
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	void SpaqnGameObject(GameObject* gameObject);
	void DespawGameObject(GameObject* gameObject);

public:
	Scene() {}
	virtual ~Scene() {}

};




