#include "pch.h"
#include "DXTextRenderer.h"
#include "GameObject.h"
#include "DXText.h"
#include "Scene.h"

void DXTextRenderer::Init()
{

}
void DXTextRenderer::D2DRender()
{
	if (pRenderTarget)
	{
		D2D1_RECT_F layoutRect = D2D1::RectF(
			_owner->GetBody().Left(),
			_owner->GetBody().Top(),
			_owner->GetBody().Right(),
			_owner->GetBody().Bottom()
			);

		Vector2 cameraPos = CurrentScene->GetCameraPos();
		layoutRect.left -= cameraPos.x;
		layoutRect.right -= cameraPos.x;
		layoutRect.top -= cameraPos.y;
		layoutRect.bottom -= cameraPos.y;

		pRenderTarget->DrawText(
			_text.c_str(),
			static_cast<uint32>(_text.length()),
			_dxTextResource->GetTextFormat(),
			layoutRect,
			_dxTextResource->GetBrush());
	}
}
void DXTextRenderer::Update()
{

}
void DXTextRenderer::Release()
{

}