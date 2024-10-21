#pragma once
#include "GameObject.h"
class Day21Brick : public GameObject
{
public:
	void Init();
	void Render(HDC hdc);
	void Update();
	void Release();
};

