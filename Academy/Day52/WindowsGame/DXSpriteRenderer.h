#pragma once
#include "Component.h"
class DXSprite;

class DXSpriteRenderer :  public Component
{
	DECLARE_CHILD(DXSpriteRenderer, Component);

public:
	virtual void Init();
	virtual void D2DRender();
	virtual void Update();
	virtual void Release();

public:
	void SetSprite(DXSprite* dxSpriteResource) { dxSpriteResource = dxSpriteResource; }
	DXSprite* GetSprite() { return _dxSpriteResource; }

protected:
	DXSprite* _dxSpriteResource = nullptr;

};

