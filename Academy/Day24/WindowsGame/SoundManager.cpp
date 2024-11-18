#include "pch.h"
#include "SoundManager.h"


void SoundManager::Init()
{
	{
		HRESULT result = DirectSoundCreate(NULL, &_soundDevice, NULL);
		if (FAILED(result))
		{
			Alert(L"Error", L"사운드 디바이스 생성 실패");
			return;
		}
	}
	{
		HRESULT result = _soundDevice->SetCooperativeLevel(_hWnd, DSSCL_PRIORITY);
		if (FAILED(result))
		{
			Alert(L"Error", L"사운드 디바이스 협조레벨 설정 실패");
			return;
		}
	}
}

void SoundManager::Release()
{
	if (_soundDevice != nullptr)
	{
		_soundDevice->Release();
	}
}

void SoundManager::Play(const wstring& key, bool loop)
{
	// 1. 리소스를 갖고온다.
	// 2. 실행시킨다.

	Sound* sound = nullptr;
}
