﻿#include "pch.h"
#include "Tilemap.h"
#include "GameObject.h"
#include "Sprite.h"

void Tilemap::SaveFile(const wstring& path)
{
	wofstream ofs;
	ofs.open(path);
	try
	{
		ofs << _mapSize.x << endl;
		ofs << _mapSize.y << endl;

		for (int y = 0; y < _mapSize.y; y++)
		{
			for (int x = 0; x < _mapSize.x; x++)
			{
				ofs << (_tiles[y][x].Value / 10) % 10;
				ofs << _tiles[y][x].Value % 10;
			}
			ofs << endl;
		}

		ofs.close();
	}
	catch (exception ex)
	{
		ofs.close();
	}
}
void Tilemap::LoadFile(const wstring& path)
{
	wifstream ifs;
	ifs.open(path);
	try
	{
		ifs >> _mapSize.x;
		ifs >> _mapSize.y;

		_tiles = vector<vector<Tile>>(_mapSize.y,vector<Tile>(_mapSize.x));

		for (int y = 0; y < _mapSize.y; y++)
		{
			wstring line;
			ifs >> line;

			for (int x = 0; x < _mapSize.x; x++)
			{
				int value10 = line[x * 2] - L'0';
				int value1 = line[x * 2 + 1] - L'0';

				_tiles[y][x].Value = value10 * 10 + value1;
			}
		}

		ifs.close();
	}
	catch (exception ex)
	{
		ifs.close();
	}
	
}

void Tilemap::Render(HDC hdc, int x, int y)
{
	int startX = 0, startY = 0;
	int endX = 0, endY = 0;

	Vector2Int screenSize = { WIN_SIZE_X,WIN_SIZE_Y };

	startX = max(-x / _tileSize.x, 0);
	startY = max(-y / _tileSize.y, 0);
	endX = min((screenSize.x - (x - _tileSize.x)) / _tileSize.x + 1, _mapSize.x);
	endY = min((screenSize.y - (y - _tileSize.y)) / _tileSize.y + 1, _mapSize.y);

	for (int my = startY; my < endY; my++)
	{
		for (int mx = startX; mx < endX; mx++)
		{
			// 1. Tile Value 가져오기
			int value = _tiles[my][mx].Value;

			if (_sprites.size() <= value)
				continue;

			// 2. 그려야하는 위치 확인
			Vector2Int renderPos = Vector2Int(
				x + mx * _tileSize.x,
				y + my* _tileSize.y
			);

			// 3. 해당 스프라이트 랜더
			_sprites[value]->Render(hdc, renderPos.x, renderPos.y);
		}
	}
}


