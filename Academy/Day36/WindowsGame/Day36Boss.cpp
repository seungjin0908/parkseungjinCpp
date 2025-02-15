﻿#include "pch.h"
#include "Day36Boss.h"

void Day36Boss::Init()
{
	Super::Init();
	_objectId = StaticObjectId++;
}
void Day36Boss::Render(HDC hdc)
{
	Super::Render(hdc);
}
void Day36Boss::Update()
{
	Super::Update();


	// 특정조건 확인
	// 코드는 D키지만,
	// 실제로 if문안에서는 무슨 서버시간을 보고있겠죠.
	if (Input->GetKeyDown(KeyCode::D))
	{
		// 보스 스폰
		GET_SINGLE(GameEventManager)->GetEvent<int>(L"AppearBoss")->Invoke(_objectId);
	}
}
void Day36Boss::Release()
{
	Super::Release();
}