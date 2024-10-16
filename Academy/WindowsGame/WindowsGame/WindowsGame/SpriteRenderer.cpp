#include "pch.h"
#include "SpriteRenderer.h"

void SpriteRenderer::Init()
{
	Super::Init();
}

void SpriteRenderer::Render(HDC hdc)
{
	Super::Render(hdc);

	Sprite* sprite = Resource->GetSprite(_info.SpriteKey);

	if (sprite == nullptr) return;

	GameObject* owner = this->GetOwner();

	if (owner == nullptr)return;

	Vector2 pos=owner.ge
}

void SpriteRenderer::Update()
{
	Super::Update();
}

void SpriteRenderer::Release()
{
	Super::Release();
}
