#pragma once
#include "Component.h"
struct TilemapRendererInfo
{

};
class TilemapRenderer : public Component
{
	DECLARE_CHILD(TilemapRenderer, Component);

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
};

