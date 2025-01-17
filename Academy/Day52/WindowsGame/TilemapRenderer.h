#pragma once
#include "Component.h"

class Tilemap;
struct TilemapRendererInfo
{
	Tilemap* Tilemap;
};

class TilemapRenderer : public Component
{
	DECLARE_CHILD(TilemapRenderer, Component)

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	void SetInfo(TilemapRendererInfo info) { _info = info; }
	TilemapRendererInfo GetInfo() { return _info; }

	// TilePos을  World Position으로 변환해주는 함수
	Vector2 GetTileWorldPosByTilePos(Vector2Int tilePos);

	// World Position을 TilePos으로 변환해주는 함수
	Vector2Int GetTilePosByWorldPos(Vector2 worldPos);
protected:
	TilemapRendererInfo _info;
};

