#pragma once
#include "Scene.h"

class DXFlipbook;
class Day48Scene : public Scene
{
	DECLARE_CHILD(Day48Scene, Scene);

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void D2DRender() override;
	virtual void Update() override;
	virtual void Release() override;

private:
	DXFlipbook* _flipbook = nullptr;
};

