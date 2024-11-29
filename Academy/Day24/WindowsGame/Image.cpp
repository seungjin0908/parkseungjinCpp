#include "pch.h"
#include "Image.h"
#include "Sprite.h"
#include "Panel.h"
void Image::Init()
{
	Super::Init();
}
void Image::Render(HDC hdc)
{
	Super::Render(hdc);

	if (_isShow == false) return;
	if (_sprite == nullptr) return;

	Panel* parent = this->GetParent();
	Vector2 renderPos = { _pos.x, _pos.y };
	while (parent != nullptr)
	{
		renderPos += parent->GetPos();
		parent = parent->GetParent();
	}

	//Vector2Int size = _sprite->GetSize();
	_sprite->Render(hdc, renderPos.x, renderPos.y);
}
void Image::Update()
{
	Super::Update();
}
void Image::Release()
{
	Super::Release();
}