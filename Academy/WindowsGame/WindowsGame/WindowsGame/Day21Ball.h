#pragma once
#include "GameObject.h"

class Day21Ball : public GameObject
{
	DELARE_CHILD(Day21Ball, GameObject);

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	void Update_Ready();
	void Update_Play();

public:
	void Move(Vector2 dir);

public:
	

private:
	float _speed = 800.0f;
};

