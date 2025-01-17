#include "pch.h"
#include "SoundManager.h"
#include "Sound.h"

void SoundManager::Init()
{
#ifdef USE_SOUND
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
#endif
}
void SoundManager::Release()
{
#ifdef USE_SOUND
	if (_soundDevice != nullptr)
	{
		_soundDevice->Release();
	}
#endif
}
void SoundManager::Play(const wstring& key, bool loop)
{
#ifdef USE_SOUND
	Sound* sound = Resource->GetSound(key);
	if (sound == nullptr)
	{
		return;
	}
	sound->Play(loop);
#endif
}
void SoundManager::Stop(const wstring& key, bool reset)
{
#ifdef USE_SOUND
	Sound* sound = Resource->GetSound(key);
	if (sound == nullptr)
	{
		return;
	}
	sound->Stop(reset);
#endif
}