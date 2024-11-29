﻿#pragma once
class SoundManager
{
	DECLARE_SINGLE(SoundManager)

public:
	void Init();
	void Release();
	void Play(const wstring& key, bool loop = false);
	void Stop(const wstring& key, bool reset = false);

	LPDIRECTSOUND GetSoundDevice()
	{
		return _soundDevice;
	}

private:
	LPDIRECTSOUND _soundDevice = nullptr;	//사운드카드 본체
};

#pragma once
class SoundManager
{
	DECLARE_SINGLE(SoundManager)

public:
	void Init();
	void Release();
	void Play(const wstring& key, bool loop = false);
	void Stop(const wstring& key, bool reset = false);

	LPDIRECTSOUND GetSoundDevice()
	{
		return _soundDevice;
	}

private:
	LPDIRECTSOUND _soundDevice = nullptr;	//사운드카드 본체
};

