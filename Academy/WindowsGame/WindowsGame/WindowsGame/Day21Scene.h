#pragma once
#include "Scene.h"
class Day21Scene : public Scene
{
	DELARE_CHILD(Day21Scene,Scene)

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
};

