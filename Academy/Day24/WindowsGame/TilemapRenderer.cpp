#include "pch.h"
#include "TilemapRenderer.h"
#include "GameObject.h"
#include "Scene.h"
#include "Tilemap.h"

void TilemapRenderer::Init()
{
	Super::Init();
}
void TilemapRenderer::Render(HDC hdc)
{
	GameObject* owner = this->GetOwner();
	if (owner == nullptr) return;

	if (_info.Tilemap == nullptr)
	{
		return;
	}

	//Vector2 pos = owner->GetPos();

	Vector2 pos;
	pos.x = owner->GetPos().x + _info.Tilemap->GetTileSize().x / 2;
	pos.y = owner->GetPos().y + _info.Tilemap->GetTileSize().y / 2;

	Vector2 cameraPos = CurrentScene->GetCameraPos();
	Vector2Int renderPos = {
		static_cast<int>(pos.x - cameraPos.x),
		static_cast<int>(pos.y - cameraPos.y)
	};

	_info.Tilemap->Render(hdc, renderPos.x, renderPos.y);

	Super::Render(hdc);
}
void TilemapRenderer::Update()
{
	Super::Update();
}
void TilemapRenderer::Release()
{
	Super::Release();
}

Vector2 TilemapRenderer::GetTileWorldPosByTilePos(Vector2Int tilePos)
{
	GameObject* owner = this->GetOwner();
	if (owner == nullptr) return Vector2::Zero();

	if (_info.Tilemap == nullptr)
	{
		return Vector2::Zero();
	}

	return owner->GetPos() + _info.Tilemap->GetTileWorldPosByTilePos(tilePos);
}

Vector2Int TilemapRenderer::GetTilePosByWorldPos(Vector2 worldPos)
{
	GameObject* owner = this->GetOwner();
	if (owner == nullptr) return { 0, 0 };

	if (_info.Tilemap == nullptr)
	{
		return { 0, 0 };
	}

	Vector2 localPosition = worldPos - owner->GetPos();

	return _info.Tilemap->GetTilePosByWorldPos(localPosition);
}