﻿#pragma once

// 미리컴파일된 헤더는 다른 cpp파일 첫번째줄에 
// #include "pch.h" 를 해줘야한다.

#define _HAS_STD_BYTE 0
//#define USE_SOUND

//==========================================
//	## Windows Api 구성에 꼭 필요한 헤더 ##
//==========================================
#include <sdkddkver.h>
#define WIN32_LEAN_AND_MEAN


#include <Windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <windowsx.h>
#include <wingdi.h>

#include <iostream>
#include <format>
#include <string>
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#pragma comment(lib, "Msimg32.lib")

//==========================================
//	## RapidJson 라이브러리 ##
//==========================================
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

using namespace rapidjson;

//==========================================
//	## C++ 관련 헤더 ##
//==========================================
#include <algorithm>
#include <string>
#include <fstream>
#include <functional>
using namespace std;

//==========================================
//	## 사운드관련 ##
//==========================================
#include <mmsystem.h>
#include <dsound.h>
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "dsound.lib")

//==========================================
//	## 자료구조 헤더 ##
//==========================================
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>


//==========================================
//	## Define 설정 ##
//==========================================
#include "Defines.h"
#include "Enums.h"
#include "IData.h"

//==========================================
//	## Types 관련 헤더 ##
//==========================================
#include "Types.h"
#include "Vector2.h"
#include "Vector2Int.h"
#include "CenterRect.h"
#include "AstarNode.h"


//==========================================
//	## Custom 헤더 ##
//==========================================
#include "CommonFunction.h"



//==========================================
//	## 매니저 헤더 ##
//=========================================
#include "RandomManager.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "CollisionManager.h"
#include "SoundManager.h"
#include "GameEventManager.h"
#include "DataManager.h"



//extern 키워드는 다른 파일에서도 쓸수있는 전역변수 선언
extern HINSTANCE	_hInstance;
extern HWND			_hWnd;