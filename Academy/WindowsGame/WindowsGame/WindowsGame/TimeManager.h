﻿#pragma once
class TimeManager
{
	DECLARE_SINGLE(TimeManager);

public:
	void Init();
	void Update();

	uint32 GetFps() { return _fps; }
	float GetDeltaTime() { return _deltaTime; }

private:
	uint32 _fps = 0;
	float _deltaTime = 0.0f;

	uint64 _frequency = 0;
	uint64 _prevCount = 0;
	float _frameTime = 0.0f;
	uint32 _frameCount = 0;
};

#define Time GET_SINGLE(TimeManager)