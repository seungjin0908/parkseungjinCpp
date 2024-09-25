# Windows API

## Windows API 란?

```
#include <Windows.h>
에 있는 함수를 사용하는게 Windows API이다.

API라는 명칭에 대해 조금 배워야하는데
Application Programming Interface
어플리케이션 프로그래밍할때 쓰이는 함수 모음집

Andorid API
 - 안드로이드 만들때 사용하는 함수모음집
```

## 그럼 굳이 Windows API를 배우는 이유
```
 게임엔진을 바로 배워서 게임을 만들수도있는데,
 게임엔진안에는 대부분의 기술이 구현되어있다.

 그래서 어떤 기술이 퍼포먼스 저하를 부르는지
 어떤 기술이 어떻게 작동하는지 알아야
 더 좋은 프로그래머가 될 수 있다.

 그래서 Windows API를 할때,
 게임을 만들때 필요한 기본으로 제공되어야할만한 기능들
 (게임엔진에서 제공하는 기능들)
 을 구현할거임.

 아무것도 안되어 있기 때문에 배우는거임.
 그렇다고 콘솔로 계속하기에는 좀 없어보이고
 기술도 조금 많이 달라짐
 Console과 Graphic의 차이가 조금 있음.
```

## Windows API 초기화

### 1. Main 문
```cpp
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nCmdShow)

	- instance
	- prevInstance
	- lpCmdLine
	- nCmdShow

	instance - 실행되고 있는 프로그램

	보통 앞에 H가 붙으면 HANDLE이라고 생각하면됨.
```


### Main문 내용
```cpp
	//1. 윈도우클래스를 등록
	MyRegisterClass(hInstance);

	//2. 윈도우를 생성
	if (false == InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	//3. 윈도우 메세지 루프
	MSG msg;
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		::TranslateMessage(&msg);
		::DispatchMessage(&msg);
	}

	윈도우 어플리케이션을 실행시키기위해서는
	제 세가지를 꼭해야됨.
	MS에서 지정한거임.
	//1. 윈도우클래스를 등록
	//2. 윈도우를 생성
	//3. 윈도우 메세지 루프
	 - 마우스를 움직이거나, 클릭을하거나
	 - 타이머를 설정했는데 타이머 시간이 됐거나,
	 - 이벤트들이 어떻게 작동할까에 대한 해석

	 - DispatchMessage를 실행시키게되면
	  실행하는 함수가 따로있음
	  (윈도우 클래스)
```

### 윈도우클래스 등록
```cpp
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEXW);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOWFRAME);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = _T("GameClient");
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	return ::RegisterClassExW(&wcex);
}
```
1. 윈도우클래스를 등록
 - MS에서 지정한 함수이기때문에 MS 문서를봐야함.

 - wcex.lpfnWndProc = WndProc;

 ### 윈도우 생성
```cpp

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	_hInstance = hInstance;

	HWND hWnd = CreateWindow(_T("GameClient"), _T("GameClient"), WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	_hWnd = hWnd;

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

// MS 가이드문서에서 CreateWindow 후에
// ShowWindow, UpdateWindow 하라고 명시되어있음.

// _hWnd - 실행되고 있는 프로그램 그자체

  instance - 프로그램별로 존재한다.
  window - 실행되는 프로그램별로 존재한다.
```

### 윈도우 프로시저
```cpp
LRESULT WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lparam)
{
	return DefWindowProc(hWnd, message, wParam, lparam);
}
// 윈도우프로시저 - 현재 메세지를 어떻게 처리할지에 대한 함수
// HWND hWnd - 지금 실행되고 있는 프로그램 (어디에 메세지가 온건지)
// UINT message - 어떤종류의 메세지가 왔는지 (마우스가 움직였는지, 마우스를 클릭했는지, 키를 눌렀는지)
// WPARAM wParam - 메세지설명1
// LPARAM lParam - 메세지설명2

마우스가 움직였다는 메세지가왔는데
마우스가 어디로 움직였는지 알방법이 없다.
wParam - x좌표
lParam - y좌표

키보드를 눌렀다
wParam - 어떤 키를 눌렀는지
lParam - 사용안함.
```