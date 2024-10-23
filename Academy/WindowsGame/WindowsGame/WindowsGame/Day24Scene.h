#pragma once
#include "Scene.h"
class Day24Scene : public Scene
{
	DELARE_CHILD(Day24Scene, Scene);
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
};

