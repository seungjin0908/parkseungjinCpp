﻿#pragma once
#include "GameObject.h"
class Day36FieldSystem : public GameObject
{
	DECLARE_CHILD(Day36FieldSystem, GameObject)

public:
	void Init();
	void Render(HDC hdc);
	void Update();
	void Release();

private:
	void OnEvent_AppearBoss(int bossId);
};

