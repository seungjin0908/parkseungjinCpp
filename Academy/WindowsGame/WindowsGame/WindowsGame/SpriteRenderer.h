#pragma once
#include "Component.h"

struct SpriteRendererInfo
{
	wstring SpriteKey;
};
class SpriteRenderer : public Component
{
	DELARE_CHILD(SpriteRenderer, Component);

public:

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	void SetInfo(SpriteRendererInfo info) { _info = info; }

protected:
	SpriteRendererInfo _info;


};

