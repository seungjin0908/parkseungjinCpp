#include "pch.h"
#include "DXFlipbookRenderer.h"
#include "DXFlipbook.h"
#include "DXSprite.h"
#include "GameObject.h"
#include "Scene.h"
void DXFlipbookRenderer::Init()
{
	Super::Init();
}
void DXFlipbookRenderer::D2DRender()
{
	Super::D2DRender();
	DXFlipbookRendererInfo info = _info;
	DXFlipbookInfo flipbookInfo = _flipbook->GetInfo();

	// 1. DXSprite 가져오기
	DXSprite* sprite = flipbookInfo.Sprite;
	if (sprite == nullptr || sprite->GetSpriteBitmap() == nullptr)
	{
		return;
	}


	// 2. Src 영역 구하기 (이미지에서 현재 보여질 영역 구하기)
	D2D1_RECT_F srcRect = {
		static_cast<float>((info.Index + flipbookInfo.Start) * flipbookInfo.Size.x),
		static_cast<float>(flipbookInfo.Line * flipbookInfo.Size.y),
		static_cast<float>((info.Index + flipbookInfo.Start) * flipbookInfo.Size.x + flipbookInfo.Size.x),
		static_cast<float>(flipbookInfo.Line * flipbookInfo.Size.y + flipbookInfo.Size.y)
	};

	// 3. Dst 영역 구하기 (화면에 보여질 영역 구하기)
	D2D1_RECT_F destRect = this->GetOwner()->GetBody().ToD2DRectF();

	Vector2 cameraPos = CurrentScene->GetCameraPos();
	destRect.left -= cameraPos.x;
	destRect.right -= cameraPos.x;
	destRect.top -= cameraPos.y;
	destRect.bottom -= cameraPos.y;


	// 4. 그리기
	pRenderTarget->DrawBitmap(
		sprite->GetSpriteBitmap(),
		destRect,
		1.0f,
		D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
		srcRect
	);
}
void DXFlipbookRenderer::Update()
{
	Super::Update();
	DXFlipbookRendererInfo info = _info;
	DXFlipbookInfo flipbookInfo = _flipbook->GetInfo();

	info.SumTime += Time->GetDeltaTime();

	if (flipbookInfo.Duration <= info.SumTime)
	{
		// 연출시간 초과
		if (flipbookInfo.Loop == true)
		{
			info.SumTime -= flipbookInfo.Duration;
		}
		else
		{
			info.Index = flipbookInfo.End;
		}
	}
	else
	{
		//연출시간중에는 계산을 해준다.
		int frameAmount = flipbookInfo.End - flipbookInfo.Start + 1;

		float frameTime = flipbookInfo.Duration / static_cast<float>(frameAmount);

		if (!EQUALS(frameTime, 0.0f))
		{
			info.Index = info.SumTime / frameTime + flipbookInfo.Start;
		}
	}

	_info = info;

}
void DXFlipbookRenderer::Release()
{
	Super::Release();
}
void DXFlipbookRenderer::SetInfo(DXFlipbookRendererInfo info)
{
	_flipbook = Resource->GetDXFlipbook(info.FlipbookKey);
	_info = info;
	_info.LastIndex = _flipbook->GetInfo().End;
}