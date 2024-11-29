#include "pch.h"
#include "Day36FieldSystem.h"

void Day36FieldSystem::Init()
{
	Super::Init();

	// 이벤트 구독
	GET_SINGLE(GameEventManager)->GetEvent<int>(L"AppearBoss")->AddListen(this, &Day36FieldSystem::onEvent_AppearBoss());
}

void Day36FieldSystem::Render(HDC hdc)
{
	Super::Render(hdc);
}

void Day36FieldSystem::Update()
{
	Super::Update();
}

void Day36FieldSystem::Release()
{
	Super::Release();
}
