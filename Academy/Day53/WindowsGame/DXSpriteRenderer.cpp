#include "pch.h"
#include "DXSpriteRenderer.h"
#include "DXSprite.h"
#include "GameObject.h"
#include "Scene.h"
void DXSpriteRenderer::Init()
{

}
void DXSpriteRenderer::D2DRender()
{
	if (_dxSpriteResource && _dxSpriteResource->GetSpriteBitmap())
	{
		auto rect = this->GetOwner()->GetBody().ToD2DRectF();

		Vector2 cameraPos = CurrentScene->GetCameraPos();
		rect.left -= cameraPos.x;
		rect.right -= cameraPos.x;
		rect.top -= cameraPos.y;
		rect.bottom -= cameraPos.y;


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