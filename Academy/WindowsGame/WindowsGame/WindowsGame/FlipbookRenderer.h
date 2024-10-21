#pragma once
#include "Component.h"

struct FlipbookRendererInfo
{
	int Index = 0;
	float SumTime = 0.0f;
};
class FlipbookRenderer : public Component
{
	DELARE_CHILD(FlipbookRenderer, Component);

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:

};

