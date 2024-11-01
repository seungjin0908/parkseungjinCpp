﻿#include "pch.h"
#include "Day26Scene.h"
#include "Tilemap.h"
#include "Sprite.h"
#include "TilemapRenderer.h"
void Day26Scene::Init()
{
	Super::Init();

	{
		vector<Sprite*> sprites;

		
		for (int i = 1; i <= 17; i++)
		{
			wstring tileTextureFileName = format(L"Day26/tile_%02d.bmp", i);
			wstring tileTextureKeyName = format(L"T_Tile_%02d", i);
			wstring tileSpriteKeyName = format(L"S_Tile_%02d", i);

			Texture* texture = Resource->LoadTexture(tileTextureKeyName, tileTextureFileName);
			Sprite* sprite = Resource->CreateSprite(tileSpriteKeyName, texture);

			sprites.push_back(sprite);
		}

		Tilemap* tilemap = Resource->LoadTilemap(L"TM_Test", L"Day26/map.txt", sprites);
	}

	{
		GameObject* gameObject = new GameObject();
		gameObject->SetPos({ 100,100 });

		{
			TilemapRenderer* component = new TilemapRenderer();
			TilemapRendererInfo info;
			info.Tilemap = Resource->GetTilemap(L"TM_Test");
		}
	}

	
}

void Day26Scene::Render(HDC hdc)
{
	Super::Render(hdc);
}

void Day26Scene::Update()
{
	Super::Update();
}

void Day26Scene::Release()
{
	Super::Release();
}
