#include "pch.h"
#include "Flipbook.h"
#include "Sprite.h"
#include "Texture.h"

void Flipbook::Render(HDC hdc, int x, int y)
{
	Texture* texture = _info.Texture;

	//Sprite* currentSprite = Sprite(texture, _index * _info.Size.x, _info.Line * _info.Size.y, _info.Size.x, _info.Size.y);
	//currentSprite.Render(hdc,x,y);

	::TransparentBlt(hdc,
		x - _info.Size.x / 2,
		y - _info.Size.y / 2,
		_info.Size.y,
		_info.Size.y,
		texture->GetDC(),
		_index * _info.Size.x,
		_info.Line * _info.Size.y,
		_info.Size.x,
		_info.Size.y,
		texture->GetTransparent()
	);
}

void Flipbook::Update()
{
	//_info.

	// 1. duration 시간동안 _index가 start ~ end까지 돌도록 만든다.
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
		int frameAmount = _info.End - _info.Start + 1;

		float frameTime = _info.Duration / static_cast<float>(frameAmount);

		if (!EQUALS(frameTime, 0.0f))
		{
			_index = _sumTime / frameTime;
		}
	}
}
