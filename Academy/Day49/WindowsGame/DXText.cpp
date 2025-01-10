#include "pch.h"
#include "DXText.h"

DXText::~DXText()
{
	if (_textFormat)
	{

	}
}

void DXText::SetInfo(DXTextInfo info)
{
	{
		HRESULT hr = DWriteCreateFactory(
			DWRITE_FACTORY_TYPE_SHARED,
			__uuidof(IDWriteFactory),
			reinterpret_cast<IUnknown**>(&_writeFactory)
		);

		pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Black), &_brush);

		assert(SUCCEEDED(hr));
	}

	{
		HRESULT hr = _writeFactory->CreateTextFormat(
			info.FontName.c_str(),
			nullptr,
			DWRITE_FONT_WEIGHT_NORMAL,
			DWRITE_FONT_STYLE_NORMAL,
			DWRITE_FONT_STRETCH_NORMAL,
			info.FontSize,
			L"ko",
			&_textFormat
		);
		assert(SUCCEEDED(hr));
	}

	_textFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING);
	_textFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_NEAR);


}
