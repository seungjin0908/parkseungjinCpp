﻿#pragma once
#include "Scene.h"
class Day33Scene : public Scene
{
	DECLARE_CHILD(Day33Scene, Scene);

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

};

