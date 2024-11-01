#include "pch.h"
#include "TilemapRenderer.h"
#include "GameObject.h"
#include "Sprite.h"
#include "Scene.h"
void TilemapRenderer::Init()
{
	Super::Init();
}

void TilemapRenderer::Render(HDC hdc)
{
	GameObject* owner = this->GetOwner();
	if (owner == nullptr)return;

	Vector2 pos = owner->GetPos();
	Vector2 cameraPos=CurrentScene.get
}

void TilemapRenderer::Update()
{
}

void TilemapRenderer::Release()
{
}
