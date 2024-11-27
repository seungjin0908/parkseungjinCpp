#pragma once
#include "Panel.h"
class GameResultPanel : public Panel
{
	DECLARE_CHILD(GameResultPanel, Panel);

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
};

