#pragma once
#include "ResourceBase.h"

struct DXSpriteInfo
{
	wstring filePath;
};

class DXSprite : public ResourceBase
{
	using Super = ResourceBase;

public:
	DXSprite() {}
	virtual ~DXSprite() {}

public:
	void SetInfo(DXSpriteInfo info);
	ID2D1Bitmap* GetSpriteBitmap() { return _spriteBitmap; }
protected:
	ID2D1Bitmap* _spriteBitmap = nullptr;
};

