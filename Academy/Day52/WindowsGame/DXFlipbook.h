#pragma once
#include "ResourceBase.h"
class DXSprite;
struct DXFlipbookInfo
{
	DXSprite* Sprite;
	Vector2Int Size;
};
class DXFlipbook : public ResourceBase
{
	DECLARE_CHILD(DXFlipbook, ResourceBase);

public:
	void SetInfo(DXFlipbookInfo)
};

