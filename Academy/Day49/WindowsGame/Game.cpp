#include "pch.h"
#include "Game.h"
#include "Scene.h"

Game::Game()
{

}
Game::~Game()
{
	GET_SINGLE(DataManager)->Release();
	GET_SINGLE(GameEventManager)->Release();
	Resource->Release();
	GET_SINGLE(SoundManager)->Release();

	if (pBrush) pBrush->Release();
	if (pRenderTarget) pRenderTarget->Release();
	if (pFactory) pFactory->Release();
}

void Game::Init(HWND hWnd)
{
	srand(time(NULL));
	this->_hwnd = hWnd;

	//1. _hdc를 유저에게 보여줄 DC로 받아준다.
	this->_hdc = ::GetDC(_hwnd);


	//==========================================
	//	## 더블버퍼링 세팅 ##
	//==========================================
	
	//2. _hdc 화면과 똑같은 크기의 화면을 생성한다.
	_hdcBack = ::CreateCompatibleDC(_hdc);
	// 윈도우의 크기를 받아옴
	::GetClientRect(_hwnd, &_rect);
	// hdc와 호환되는 비트맵 생성
	_bmpBack = ::CreateCompatibleBitmap(_hdc, _rect.right, _rect.bottom);
	//_hdcBack에 _bmpBack 연결
	HBITMAP prev = (HBITMAP)SelectObject(_hdcBack, _bmpBack);
	// 기존에 적용되어있던 _hdcBack 비트맵 삭제
	DeleteObject(prev);


	Input->Init(_hwnd);
	Time->Init();
	Resource->Init();
	GET_SINGLE(SoundManager)->Init();
	GET_SINGLE(CollisionManager)->Init();
	GET_SINGLE(SceneManager)->Init();
	GET_SINGLE(GameEventManager)->Init();
	GET_SINGLE(DataManager)->Init();
	GET_SINGLE(SceneManager)->ChangeScene(SceneType::Day48Scene);
}

void Game::Update()
{
	GET_SINGLE(CollisionManager)->Update();
	Input->Update();
	Time->Update(); 
	GET_SINGLE(SceneManager)->Update();
}

void Game::Render()
{
	

	if (pRenderTarget)
	{
		// 1. 렌더링 시작
		pRenderTarget->BeginDraw();

		// 2. 화면을 지움 (이전의 PatBlt 역할)
		pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::White));

		// 이 사이에만 그림을 그릴 수 있다.

		//FPS 출력
		{
			uint32 fps = Time->GetFps();
			float deltaTime = Time->GetDeltaTime();

			wstring timeStr = ::format(L"FPS({}), DeltaTime({} ms)", fps, static_cast<int32>(deltaTime * 1000));
			{
				// 1. 텍스트를 출력할 영역 지정
				D2D1_RECT_F layoutRect = D2D1::RectF(0, 0, 300, 50);

				// 2. 텍스트 색상 설정

				if (FAILED(hr))
				{
					return hr;
				}

				hr = pRenderTarget->CreateSolidColorBrush(
					D2D1::ColorF(D2D1::ColorF::SkyBlue),
					&pBrush
				);

				if (FAILED(hr))
				{
					return hr;
				}

				hr = DWriteCreateFactory(
					DWRITE_FACTORY_TYPE_SHARED,
					__uuidof(IDWriteFactory),
					reinterpret_cast<IUnknown**>(*pDwriteFactory)
				);

				if (SUCCEEDED(hr))
				{
					hr = pDwriteFactory->CreateTextFormat(
						L"Arial",							// 폰트이름
						nullptr,
						DWRITE_FONT_WEIGHT_NORMAL,
						DWRITE_FONT_STYLE_NORMAL,
						DWRITE_FONT_STRETCH_NORMAL,
						8.0f,
						L"en-us",
						&pTextFormat
					);
				}

				if (SUCCEEDED(hr))
				{
					pTextFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING);
					pTextFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_NEAR);
				}

				// 3. 텍스트 출력
				pRenderTarget->DrawText(
					timeStr.c_str(),							// 문자열
					static_cast<uint32>(timeStr.length()),		// 문자열 길이
					pTextFormat,								// 텍스트 포맷
					layoutRect,
					pBrush
				);

				return hr;
			}
		}
		GET_SINGLE(SceneManager)->D2DRender();

		pRenderTarget->EndDraw();
	}
	else
	{
		////FPS 출력
		//{
		//	uint32 fps = Time->GetFps();
		//	float deltaTime = Time->GetDeltaTime();

		//	wstring timeStr = ::format(L"FPS({}), DeltaTime({} ms)", fps, static_cast<int32>(deltaTime * 1000));
		//	Draw::Text(_hdcBack, 0, 0, timeStr);
		//}

		

		////==========================================
		////	## 더블버퍼링 세팅 ##
		////==========================================

		//// 1. hdcBack의 내용을  hdc로 복사한다.
		//BitBlt(_hdc, 0, 0, _rect.right, _rect.bottom, _hdcBack, 0, 0, SRCCOPY);

		//// 2. hdcBack의 내용을 깨끗이 지운다.
		//PatBlt(_hdcBack, 0, 0, _rect.right, _rect.bottom, WHITENESS);

		// 모두 Windows API를 활용해서 그림을 그리고 있었다.
	}
}

HRESULT Game::InitDirect2D(HWND hWnd)
{
	// Direct 2D 팩토리 생성 
	HRESULT hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &pFactory);

	if (FAILED(hr))
	{
		return hr;
	}

	RECT rc;
	GetClientRect(hWnd, &rc);

	D2D1_SIZE_U size = D2D1::SizeU(
		rc.right - rc.left,
		rc.bottom - rc.top
	);

	// 랜더 타겟 생성
	hr = pFactory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(hWnd, size),
		&pRenderTarget
	);

	

	
	
}