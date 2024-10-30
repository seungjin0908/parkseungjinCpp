#include "pch.h"
#include "Tilemap.h"
#include "GameObject.h"
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
