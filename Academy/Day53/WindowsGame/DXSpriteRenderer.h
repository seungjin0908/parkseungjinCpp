#pragma once
#include "Component.h"
class DXSprite;

class DXSpriteRenderer : public Component
{
	DECLARE_CHILD(DXSpriteRenderer, Component);

public:
	virtual void Init() override;
	virtual void D2DRender() override;
	virtual void Update() override;
	virtual void Release() override;

public:
	void SetSprite(DXSprite* dxSpriteResource) { _dxSpriteResource = dxSpriteResource; }
	DXSprite* GetSprite() { return _dxSpriteResource; }

protected:
	DXSprite* _dxSpriteResource = nullptr;
};

