#pragma once
#include "GameObject.h"
class Day36Character : public GameObject
{
	DECLARE_CHILD(Day36Character, GameObject)

public:
	void Init();
	void Render(HDC hdc);
	void Update();
	void Release();


public:
	int GetHp() { return _hp; }
	void SetHp(int hp);
private:
	int _hp = 100;
};

