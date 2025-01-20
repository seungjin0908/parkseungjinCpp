#include "pch.h"
#include "DXFlipbook.h"
#include "DXSprite.h"


void DXFlipbook::D2DRender(int x, int y, int width, int height)
{
	// 1. DXSprite 가져오기
	DXSprite* sprite = _info.Sprite;
	if (sprite == nullptr || sprite->GetSpriteBitmap() == nullptr)
	{
		return;
	}


	// 2. Src 영역 구하기 (이미지에서 현재 보여질 영역 구하기)
	D2D1_RECT_F srcRect = {
		static_cast<float>((_index + _info.Start) * _info.Size.x),
		static_cast<float>(_info.Line * _info.Size.y),
		static_cast<float>((_index + _info.Start) * _info.Size.x + _info.Size.x),
		static_cast<float>(_info.Line * _info.Size.y + _info.Size.y)
	};

	// 3. Dst 영역 구하기 (화면에 보여질 영역 구하기)
	D2D1_RECT_F destRect = {
		static_cast<float>(x - width / 2),
		static_cast<float>(y - height / 2),
		static_cast<float>(x + width / 2),
		static_cast<float>(y + height / 2),
	};

	// 4. 그리기
	pRenderTarget->DrawBitmap(
		sprite->GetSpriteBitmap(),
		destRect,
		1.0f,
		D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
		srcRect
	);

}
void DXFlipbook::Update()
{
	_sumTime += Time->GetDeltaTime();

	if (_info.Duration <= _sumTime)
	{
		// 연출시간 초과
		if (_info.Loop == true)
		{
			_sumTime -= _info.Duration;
		}
		else
		{
			_index = _info.End;
		}
	}
	else
	{
		//연출시간중에는 계산을 해준다.
		int frameAmount = _info.End - _info.Start + 1;

		float frameTime = _info.Duration / static_cast<float>(frameAmount);

		if (!EQUALS(frameTime, 0.0f))
		{
			_index = _sumTime / frameTime;
		}
	}
}