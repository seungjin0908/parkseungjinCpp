#pragma once
class Day17Player;
class Day17Box;
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
	Scene() {}
	virtual ~Scene() {}

private:
	Day17Player* _player;
	Day17Box* _box;

};


