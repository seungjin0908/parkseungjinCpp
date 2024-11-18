#pragma once
#include "ResourceBase.h"


class Sound : public ResourceBase
{
public:
	using Super = ResourceBase;

	Sound();
	virtual ~Sound();

public:
	bool LoadWave(const wstring& path);
	void Play(bool loop = false);
	void Stop(bool reset = false);

private:
	DSBUFFERDESC _bufferDesc = {};
	LPDIRECTSOUNDBUFFER _soundBuffer = nullptr;
};

