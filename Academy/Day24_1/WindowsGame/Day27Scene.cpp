#include "pch.h"
#include "Day27Scene.h"
#include "Tilemap.h"
#include "Sprite.h"
#include "TilemapRenderer.h"
#include "GameObject.h"
#include "Day27Creature.h"
void Day27Scene::Init()
{
	Super::Init();
	// 타일맵 소환


	{
		vector<Sprite*> sprites;

		sprites.push_back(nullptr);
		for (int i = 1; i <= 17; i++)
		{
			wstring tileTextureFileName = format(L"Day26/tile_{:02d}.bmp", i);
			wstring tileTextureKeyName = format(L"T_Tile_{:02d}", i);
			wstring tileSpriteKeyName = format(L"S_Tile_{:02d}", i);

			Texture* texture = Resource->LoadTexture(tileTextureKeyName, tileTextureFileName);
			Sprite* sprite = Resource->CreateSprite(tileSpriteKeyName, texture);

			sprites.push_back(sprite);
		}

		//Tilemap 로드
		Tilemap* tilemap = Resource->LoadTilemap(L"TM_Test", L"Day26/map.txt", sprites);
	}


	{
		GameObject* gameObject = new GameObject();
		gameObject->Init();
		gameObject->SetPos({ 0, 0 });
		gameObject->SetLayerType(LayerType::BackGround);

		{
			TilemapRenderer* component = new TilemapRenderer();
			TilemapRendererInfo info;
			info.Tilemap = Resource->GetTilemap(L"TM_Test");
			component->SetInfo(info);
			gameObject->AddComponent(component);
			_tilemapRenderer = component;
		}

		//this->SpawnGameObject(gameObject);
		_tilemapGameObject = gameObject;
	}

	{
		Day27Creature* gameObject = new Day27Creature();
		gameObject->Init();
		gameObject->SetLayerType(LayerType::Character);
		{
			Vector2Int tilePos = { 2, 7 };
			Vector2 pos = _tilemapRenderer->GetTileWorldPosByTilePos(tilePos);
			gameObject->SetPos(pos);
			gameObject->SetTilePos(tilePos);
		}
		_creature = gameObject;
	}

	this->SpawnGameObject(_creature);
	this->SpawnGameObject(_tilemapGameObject);

}
void Day27Scene::Render(HDC hdc)
{
	Super::Render(hdc);
	//씬 이름 출력
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


}
void Day27Scene::Release()
{
	Super::Release();
}

void Day27Scene::Update_MapTool()
{

	if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		// 1. 해당위치의 타일을 가져온다
		Tilemap* tilemap = _tilemapRenderer->GetInfo().Tilemap;
		if (tilemap == nullptr)
		{
			return;
		}

		//GetTileAt를 사용하기위해서는 인덱스 계산이 필요합니다.
		// 실제 위치
		//_tilemap->GetPos() + 인덱스 * _tilemap->GetTileSize()
		//Input->GetMousePosVector2().x 이 좌표가 타일맵의 어떤 인덱스인지 구하는 공식
		Vector2 temp = Input->GetMousePosVector2() - _tilemapGameObject->GetPos();
		int x = static_cast<int>(temp.x / tilemap->GetTileSize().x);
		int y = static_cast<int>(temp.y / tilemap->GetTileSize().y);

		//cout << "X : " << x << endl;
		//cout << "Y : " << y << endl;
		Vector2Int mapSize = tilemap->GetMapSize();

		// Validation Check
		if (mapSize.x <= x || x < 0)
		{
			return;
		}
		if (mapSize.y <= y || y < 0)
		{
			return;
		}

		Tile tile = tilemap->GetTileAt({ x, y });

		// 2. 해당 타일의 값을 1올린다.
		tile.Value += 1;
		if (tilemap->GetSprites().size() <= tile.Value)
		{
			tile.Value = 1;
		}

		// 3. 해당 타일을 적용한다.
		tilemap->SetTileAt({ x, y }, tile);
	}

	if (Input->GetKeyDown(KeyCode::S))
	{
		Tilemap* tilemap = _tilemapRenderer->GetInfo().Tilemap;

		tilemap->SaveFile(L"../Resources/Day26/newMap.txt");
	}

	if (Input->GetKeyDown(KeyCode::L))
	{
		Tilemap* tilemap = _tilemapRenderer->GetInfo().Tilemap;

		tilemap->LoadFile(L"../Resources/Day26/newMap.txt");
	}
}

void Day27Scene::Update_CharacterMove()
{
	if (Input->GetKeyDown(KeyCode::RightMouse))
	{
		//누른 스크린좌표를 타일값좌표로 변환
		Vector2 mousePos = Input->GetMousePosVector2();
		Vector2 worldPos = ScreenPosToWorldPos(mousePos);
		
		Vector2Int tilePos = _tilemapRenderer->GetTilePosByWorldPos(worldPos);
		printf("클릭한 지점 : [%d, %d]\n", tilePos.x, tilePos.y);

		TilemapRendererInfo info = _tilemapRenderer->GetInfo();
		
		if (info.Tilemap == nullptr)
		{
			return;
		}

		Vector2Int characterTilePos = info.Tilemap->GetTilePosByWorldPos(_creature->GetPos());
		vector<Vector2Int> paths = info.Tilemap->Calculate_Astar(characterTilePos, tilePos);

		vector<Vector2> creaturePath = {};
		for (Vector2Int path : paths)
		{
			printf(" -path  %d, %d\n", path.x, path.y);

			creaturePath.push_back(info.Tilemap->GetTileWorldPosByTilePos(path));
		}
		_creature->SetPath(creaturePath);
	}
}