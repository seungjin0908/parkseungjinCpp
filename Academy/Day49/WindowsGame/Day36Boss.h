#pragma once
#include "GameObject.h"
class Day36Boss : public GameObject
{
	DECLARE_CHILD(Day36Boss, GameObject)

public:
	void Init();
	void Render(HDC hdc);
	void Update();
	void Release();
private:
};

