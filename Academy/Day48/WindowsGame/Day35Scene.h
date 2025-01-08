#pragma once
#include "Scene.h"
class Day35Scene : public Scene
{
	DECLARE_CHILD(Day35Scene, Scene);

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	void AddCount() { _count++; }

private:
	int _count = 0;

};

