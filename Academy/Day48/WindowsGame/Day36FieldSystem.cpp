#include "pch.h"
#include "Day36FieldSystem.h"

void Day36FieldSystem::Init()
{
	Super::Init();
	_objectId = StaticObjectId++;

	//이벤트 구독
	GET_SINGLE(GameEventManager)->GetEvent<int>(L"AppearBoss")->AddListen(this, &Day36FieldSystem::OnEvent_AppearBoss);
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
void Day36FieldSystem::OnEvent_AppearBoss(int bossId)
{
	if (bossId <= 100)
	{
		printf("보스 효과로 인해, 필드가 얼어 붙었습니다.\n");
	}
	else
	{
		printf("보스 효과로 인해, 필드가 불타고 있습니다.\n");
	}
}