#pragma once
#include "ResourceBase.h"

struct DXTextInfo
{
	float FontSize;
	wstring FontName;
	//D2D1::ColorF Color;
};

class DXText : public ResourceBase
{
	using Super = ResourceBase;

public:
	DXText() {}
	virtual ~DXText();

public:
	void SetInfo(DXTextInfo info);
	IDWriteTextFormat* GetTextFormat() { return _textFormat; }
	ID2D1SolidColorBrush* GetBrush() { return _brush; }

protected:
	IDWriteFactory* _writeFactory = nullptr;
	IDWriteTextFormat* _textFormat = nullptr;
	ID2D1SolidColorBrush* _brush = nullptr;
};

