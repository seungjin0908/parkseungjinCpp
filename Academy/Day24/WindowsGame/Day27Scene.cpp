#include "pch.h"
#include "Day27Scene.h"
#include "GameObject.h"
#include "TilemapRenderer.h"
#include "Tilemap.h"
void Day27Scene::Init()
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

void Day27Scene::Render(HDC hdc)
{
	Super::Render(hdc);

	{
		wstring nameStr = ::format(L"Day27Scene");
		Draw::Text(hdc, 0, 20, nameStr);
	}
}

void Day27Scene::Update()
{
	Super::Update();
	
	//Update_MapTool();
	Update_CharacterMove();


	if (Input->GetKeyDown(KeyCode::K))
	{
		Vector2 v1 = Vector2(0, 1);
		Vector2 v2 = Vector2(1, 1).Normalize();
	}
}

void Day27Scene::Release()
{
	Super::Release();
}
