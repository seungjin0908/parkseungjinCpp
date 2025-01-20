#include "pch.h"
#include "DXSprite.h"


void DXSprite::SetInfo(DXSpriteInfo info)
{
	// Windows API를 사용합니다.

	// 1) WIC 팩토리 생성
	IWICImagingFactory* wicFactory = nullptr;
	HRESULT hr = CoCreateInstance(
		CLSID_WICImagingFactory,
		nullptr,
		CLSCTX_INPROC_SERVER,
		IID_PPV_ARGS(&wicFactory)
	);
	if (FAILED(hr))
	{
		return;
	}

	// 2) 디코더 생성
	IWICBitmapDecoder* wicDecoder = nullptr;
	hr = wicFactory->CreateDecoderFromFilename(
		info.filePath.c_str(),
		nullptr,
		GENERIC_READ,
		WICDecodeMetadataCacheOnLoad,
		&wicDecoder
	);
	
	if (FAILED(hr))
	{
		wicFactory->Release();
		wicFactory = nullptr;
		return;
	}


	// 3) 프레임 가져오기
	IWICBitmapFrameDecode* wicFrame = nullptr;
	hr = wicDecoder->GetFrame(0, &wicFrame);

	if (FAILED(hr))
	{
		wicDecoder->Release();
		wicDecoder = nullptr;

		wicFactory->Release();
		wicFactory = nullptr;
		return;
	}


	// 4) 포맷변환
	IWICFormatConverter* wicConverter = nullptr;
	wicFactory->CreateFormatConverter(&wicConverter);
	
	if (FAILED(hr))
	{
		wicFrame->Release();
		wicFrame = nullptr;

		wicDecoder->Release();
		wicDecoder = nullptr;

		wicFactory->Release();
		wicFactory = nullptr;
		return;
	}


	// 5) 픽셀 포맷을 RGBA로 맞춤
	hr = wicConverter->Initialize(
		wicFrame,
		GUID_WICPixelFormat32bppPBGRA,	// 32비트 RGBA 포맷
		WICBitmapDitherTypeNone,
		nullptr,
		0,
		WICBitmapPaletteTypeCustom
	);


	if (FAILED(hr))
	{
		wicConverter->Release();
		wicConverter = nullptr;

		wicFrame->Release();
		wicFrame = nullptr;

		wicDecoder->Release();
		wicDecoder = nullptr;

		wicFactory->Release();
		wicFactory = nullptr;
		return;
	}

	

	// 6) Convert한 WIC 비트맵을 Direct2D 비트맵으로 변환
	hr = pRenderTarget->CreateBitmapFromWicBitmap(
		wicConverter,
		nullptr,
		&_spriteBitmap
	);
	assert(SUCCEEDED(hr));


	// 7) 리소스 사용 해제
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

	if (wicFactory)
	{
		wicFactory->Release();
		wicDecoder = nullptr;
	}
}