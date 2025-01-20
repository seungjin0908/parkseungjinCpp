#pragma once
#include "Component.h"

struct DXFlipbookRendererInfo
{
	wstring FlipbookKey;
	int Index = 0;
	float SumTime = 0.0f;
	int LastIndex = 0;

	Vector2 Offest = {};
};

class DXFlipbookRenderer : public Component
{
	DECLARE_CHILD(DXFlipbookRenderer, Component);

public:
	virtual void Init();
	virtual void D2DRender();
	virtual void Update();
	virtual void Release();
public:
	void SetInfo(DXFlipbookRendererInfo info);
	DXFlipbookRendererInfo GetInfo() { return _info; }

protected:
	DXFlipbookRendererInfo _info;
	DXFlipbook* _flipbook = nullptr;
};



