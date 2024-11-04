﻿#include "pch.h"
#include "Board.h"
#include "ConsoleHelper.h"
void Board::Init()
{
	_size = 25; // 사이즈는 홀수이어야한다.

	_mapInfo = vector<vector<TileType>>(_size, 
	vector<TileType>(_size, TileType::Wall));

	this->GenerateMap();
}
void Board::GenerateMap()
{
	srand(time(NULL));
	for (int y = 0; y < _size; y++)
	{
		for (int x = 0; x < _size; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
			{
				_mapInfo[y][x] = TileType::Wall;
			}
			else
			{
				_mapInfo[y][x] = TileType::Empty;
			}
		}
	}

	//랜덤으로 우측 혹은 아래로 길을 뚫는 작업
	for (int y = 0; y < _size - 1; y++)
	{
		for (int x = 0; x < _size - 1; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
			{
				continue;
			}

			// 맨 아래에서는 하단벽 못 지우게 하기
			if (y == _size - 2)
			{
				_mapInfo[y][x + 1] = TileType::Empty;
				continue;
			}

			int randomValue = rand() % 2;
			if (randomValue == 0)
			{
				//오른쪽으로 길 뚫기
				_mapInfo[y][x + 1] = TileType::Empty;
			}
		}
	}
}

void Board::Render()
{
	ConsoleHelper::SetCursorPosition(0, 0);
	ConsoleHelper::ShowConsoleCursor(false);

	for (int y = 0; y < _size; y++)
	{
		for (int x = 0; x < _size; x++)
		{
			switch (_mapInfo[y][x])
			{
			default:
				break;
			}
		}
	}
}
