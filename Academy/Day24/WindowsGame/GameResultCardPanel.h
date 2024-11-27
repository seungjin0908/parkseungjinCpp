#pragma once
#include "Panel.h"
class GameResultCardPanel : public Panel
{
	DECLARE_CHILD(GameResultCardPanel, Panel);

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
};

