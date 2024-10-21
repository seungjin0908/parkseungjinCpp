#include "pch.h"
#include "Day23Scene.h"
#include "Flipbook.h"
#include "Texture.h"

void Day23Scene::Init()
{
	Texture* texture = Resource->LoadTexture(L"T_character", L"Day23/spritesheet_character");

	{
		FlipbookInfo flipbookInfo;
		flipbookInfo.Duration = 2.0f;
		flipbookInfo.Start = 0;
		flipbookInfo.End = 6;
		flipbookInfo.Line = 1;
		flipbookInfo.Loop = true;
		flipbookInfo.Size = Vector2Int(50, 37);
		flipbookInfo.Texture = texture;
		Resource.createFlipbook
	}
}

void Day23Scene::Render(HDC hdc)
{
}

void Day23Scene::Update()
{
}

void Day23Scene::Release()
{
}
