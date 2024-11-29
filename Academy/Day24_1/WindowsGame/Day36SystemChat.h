#pragma once
#include "GameObject.h"
class Day36SystemChat : public GameObject
{
	DECLARE_CHILD(Day36SystemChat, GameObject)

public:
	void Init();
	void Render(HDC hdc);
	void Update();
	void Release();

private:
	void OnEvent_Boss
};

