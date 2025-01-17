#include "pch.h"
#include "DXFlipbookRenderer.h"
#include "DXFlipbook.h"
#include "DXSprite.h"
#include "GameObject.h"
void DXFlipbookRenderer::Init()
{
	Super::Init();
}
void DXFlipbookRenderer::D2DRender()
{
	Super::D2DRender();
	DXFlipbookRendererInfo info = _info;
	DXFlipbookInfo flipbookInfo = _flipbook->GetInfo();
}
void DXFlipbookRenderer::Update()
{
	Super::Update();
}
void DXFlipbookRenderer::Release()
{
	Super::Release();
}
void DXFlipbookRenderer::SetInfo(DXFlipbookRendererInfo info)
{
	_flipbook =Resource
}
