﻿#pragma once
#include "ResourceBase.h"

struct Tile
{
	int Value;
};

class Tilemap :  public ResourceBase
{
	DECLARE_CHILD(Tilemap, ResourceBase);

public:
	void SaveFile(const wstring& path);
	void LoadFile(const wstring& path);

public:
	Vector2Int GetMapSize() { return _mapSize; }
	void SetMapSize(Vector2Int mapSize) { _mapSize = mapSize; }

	Vector2Int GetTileSize() { return _tileSize; }
	void SetTileSize(Vector2Int tileSize) { _tileSize = tileSize; }

	Tile GetTileAt(Vector2Int pos) { return _tiles[pos.y][pos.x]; }
	void SetTileAt(Vector2Int pos, Tile tile) { _tiles[pos.y][pos.x]=tile; }
	void SetTiles(vector<vector<Tile>>tiles) { _tiles = tiles; }
	

	void SetSprites(vector<Sprite*> sprites);


public:
	void Render(HDC hdc, int x, int y);

protected:
	// 맵크기 (10 * 9)
	Vector2Int _mapSize = {};
	// 타일하나당 크기 (53 * 49)
	Vector2Int _tileSize = {};

	// 2차원 배열로 타일리스트를 들고있어야함
	vector<vector<Tile>> _tiles;

	vector<Sprite*> _sprites;
};

