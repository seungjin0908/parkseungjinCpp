#include "pch.h"
#include "DXSprite.h"


void DXSprite::SetInfo(DXSpriteInfo info)
{
	// Windows API를 사용한다.

	// 1) WID 팩토리 생성
	IWICImagingFactory* wicFactory = nullptr;
	HRESULT hr = CoCreateInstance(
		CLSID_WICImagingFactory,
		nullptr,
		CLSCTX_INPROC_SERVER,
		IID_PPV_ARGS(&wicFactory)
	);
	if (FAILED(hr))
	{
		
	}

	assert(SUCCEEDED(hr));

	// 2) 디코더 생성
	IWICBitmapDecoder* wicDecoder = nullptr;
	hr = wicFactory->CreateDecoderFromFilename(
		info.filePath.c_str(),
		nullptr,
		GENERIC_READ,
		WICDecodeMetadataCacheOnLoad,
		&wicDecoder
	);
	assert(SUCCEEDED(hr));

	// 3) 프레임 가져오기
	IWICBitmapFrameDecode* wicFrame = nullptr;
	hr = wicDecoder->GetFrame(0, &wicFrame);
	assert(SUCCEEDED(hr));

	// 4) 포맷변환
	IWICFormatConverter* wicConverter = nullptr;
	wicFactory->CreateFormatConverter(&wicConverter);
	assert(SUCCEEDED(hr));

	// 5) 픽셀 포맷을 RGBA로 맞춤
	hr = wicConverter->Initialize(
		wicFrame,
		GUID_WICPixelFormat32bppPBGRA,	// 32비트 RGBA 포맷
		WICBitmapDitherTypeNone,
		nullptr,
		0,
		WICBitmapPaletteTypeCustom
	);
	assert(SUCCEEDED(hr));

	// 6) Converter한 WIC 비트맵을 Direct2D 비트맵으로 변환
	hr = pRenderTarget->CreateBitmapFromWicBitmap(
		wicConverter,
		nullptr,
		&_spriteBitmap
	);
	assert(SUCCEEDED(hr));

	if (wicConverter)
	{
		wicConverter->Release();
		wicConverter = nullptr;
	}

	if (wicFrame)
	{
		wicFrame->Release();
		wicFrame = nullptr;
	}

	if (wicDecoder)
	{
		wicDecoder->Release();
		wicDecoder = nullptr;
	}
}