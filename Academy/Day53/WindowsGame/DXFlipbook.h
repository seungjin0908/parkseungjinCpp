#pragma once
#include "ResourceBase.h"
class DXSprite;
struct DXFlipbookInfo
{
	DXSprite* Sprite;
	Vector2Int Size;
	int Start;
	int End;
	int Line;
	float Duration;
	bool Loop;
};

class DXFlipbook : public ResourceBase
{
	DECLARE_CHILD(DXFlipbook, ResourceBase);

public:
	void SetInfo(DXFlipbookInfo info) { _info = info; }
	DXFlipbookInfo GetInfo() { return _info; }

	void D2DRender(int x, int y, int width, int height);
	void Update();
protected:
	DXFlipbookInfo _info;

	int _index = 0;
	float _sumTime = 0.0f;
};