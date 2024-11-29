#pragma once
#include "Scene.h"
class GameObject;
class TilemapRenderer;
class Day27Creature;
class Day27Scene : public Scene
{
	DECLARE_CHILD(Day27Scene, Scene);

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	void Update_MapTool();
	void Update_CharacterMove();

private:
	GameObject* _tilemapGameObject = nullptr;
	TilemapRenderer* _tilemapRenderer = nullptr;
	Day27Creature* _creature = nullptr;
};

