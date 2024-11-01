#pragma once
#include "Scene.h"
class Day27Scene : public Scene
{
	DECLARE_CHILD(Day27Scene, Scene);
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

private:
	GameObject* _tilemap = nullptr;
	TilemapRenderer* _tilemapRenderer = nullptr;
};

