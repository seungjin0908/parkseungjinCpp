#include "pch.h"
#include "Day19Stone.h"
#include "Sprite.h"

void Day19Stone::Init()
{
}

void Day19Stone::Render(HDC hdc)
{
	int renderX = 100;
	int renderY = 100;
	if (_type == 0)
	{

	}
}

void Day19Stone::Update()
{
}

void Day19Stone::Release()
{
}

void Day19Stone::SetInfo(Vector2Int pos, int type)
{
	_pos = pos;
	_type = type;
}
