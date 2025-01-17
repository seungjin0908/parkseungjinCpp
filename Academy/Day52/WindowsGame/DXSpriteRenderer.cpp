#include "pch.h"
#include "DXSpriteRenderer.h"
#include "DXSprite.h"
#include "GameObject.h"
void DXSpriteRenderer::Init()
{

}
void DXSpriteRenderer::D2DRender()
{
	if (_dxSpriteResource && _dxSpriteResource->GetSpriteBitmap())
	{
		auto rect = this->GetOwner()->GetBody().ToD2DRectF();

		pRenderTarget->DrawBitmap(
			_dxSpriteResource->GetSpriteBitmap(),
			rect
		);
	}
}
void DXSpriteRenderer::Update()
{

}
void DXSpriteRenderer::Release()
{

}
