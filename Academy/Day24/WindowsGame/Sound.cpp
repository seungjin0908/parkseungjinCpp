﻿#include "pch.h"
#include "Sound.h"

Sound::Sound()
{

}

Sound::~Sound()
{
	if (_soundBuffer)
	{
		_soundBuffer->Release();
	}
}

bool Sound::LoadWave(const wstring& path)
{
	// .wav
	HMMIO file = mmioOpen((wchar_t*)path.c_str(), NULL, MMIO_READ);
	if (file == NULL)
	{
		Alert(L"Error", L"사운드 파일 / 인식 못함");
		return false;
	}

	MMCKINFO parent;
	memset(&parent, 0, sizeof(parent));
	//ZeroMemory(&parent, sizeof(parent));

	parent.fccType = mmioFOURCC('W', 'A', 'V', 'E');
	mmioDescend(file, &parent, NULL, MMIO_FINDRIFF);

	MMCKINFO child;
	memset(&child, 0, sizeof(child));
	child.ckid = mmioFOURCC('f', 'm', 't', ' ');
	mmioDescend(file, &child, &parent, MMIO_FINDCHUNK);

	WAVEFORMATEX wft;
	memset(&wft, 0, sizeof(wft));
	mmioRead(file, (char*)&wft, sizeof(wft));

	mmioAscend(file, &child, 0);
	child.ckid = mmioFOURCC('d', 'a', 't', 'a');
	mmioDescend(file, &child, &parent, MMIO_FINDCHUNK);

	memset(&_bufferDesc, 0, sizeof(DSBUFFERDESC));
	_bufferDesc.dwBufferBytes = child.cksize;
	_bufferDesc.dwFlags = DSBCAPS_STATIC;
	_bufferDesc.dwSize = sizeof(DSBUFFERDESC);
	_bufferDesc.lpwfxFormat = &wft;

	// 사운드버퍼 생성
	// 사운드카드에서 사운드버퍼를 가져와서 거기에 입혀야하는데,
	// 사운드 Device는 SoundManager에서 만들어둘거임.
	// 그래서 있다고 가정하고 이어서 짠다음에
	// 사운드매니저 다만들고 다시와서 살짝 수정할거임.
	LPDIRECTSOUND soundDevice;
	// LPDIRECTSOUND soundDevice = GET_SINGLE(SoundManager)->GetSoundDevice();
	HRESULT result = soundDevice->CreateSoundBuffer(&_bufferDesc, &_soundBuffer, NULL);
	if (FAILED(result))
	{
		Alert(L"Error", L"사운드 버퍼 생성 실패");
		return false;
	}

	// 여기부터는 로직은 안 중요함.
	// C++에서만 가능한 포인터의 꼼수가 나온다.
	// 요거는 C++을 많이 알수로 많이 사용하게되는 방식이니까 눈에 익혀두면 좋음.

	// void* << void형을 담고있는 4바이트 포인터 (주솟값을 담을 수 있는 자료형)
	//			그런데 담고있는 주소가 어떤 자료형인지는 모르는.
	void* write1 = NULL;
	void* write2 = NULL;

	DWORD len1;
	DWORD len2;

	// 버퍼를 다룰때는 항상
	// 락을 걸고
	// 버퍼를 사용하고
	// 락을 푸는 형태로 사용한다.

	// Lock의 의미


	// 버퍼라는건
	// 여러군데에서 사용 가능함.
	// 동시에 자원을 접급하면 컴퓨터 뻑난다.
	// 블루스크린 (OS차원)

	// 프로그램내에서 동시에 자원을 접근한다. (변수)
	// 멀티스레드 할때 잠깐 생각하면 좋다.
	// 동시에 자원을 접근하면
	// 프로그램이 뻑난다.
	// 강제종료 된다.

	// Lock의 의미
	// 내가 락을 걸고 사용할거니까 다른사람들은 그동안 기다려
	// 라는 뜻이다.

	// 1. 락을 건다.
	_soundBuffer->Lock(0, child.cksize, &write1, &len1, &write2, &len2, 0);
	
	// 2. 사용한다
	if (write1)
	{

	}
}

void Sound::Play(bool loop)
{
	if (loop)
	{
		_soundBuffer->Play(0, 0, DSBPLAY_LOOPING);
	}
	else
	{
		_soundBuffer->Play(0, 0, 0);
	}
}

void Sound::Stop(bool reset)
{
	_soundBuffer->Stop();

	if (reset)
	{
		_soundBuffer->SetCurrentPosition(0);
	}
}
