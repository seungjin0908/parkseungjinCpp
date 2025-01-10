#include "pch.h"
#include "DXTextRenderer.h"
#include "GameObject.h"
#include "DXText.h"

void DXTextRenderer::Init()
{

}
void DXTextRenderer::D2DRender()
{
	if (pRenderTarget)
	{
		D2D1_RECT_F layouRect = D2D1::RectF(
			_owner->GetBody().Left(),
			_owner->GetBody().Top(),
			_owner->GetBody().Right(),
			_owner->GetBody().Bottom()
		);

		pRenderTarget->DrawText(
			_text.c_str(),
			static_cast<uint32>(_text.length()),
			_dxTextResource->GetTextFormat(),
			layouRect,
			_dxTextResource->GetBrush()
		);
	}
}
void DXTextRenderer::Update()
{

}
void DXTextRenderer::Release()
{

}
