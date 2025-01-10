#include "pch.h"
#include "Day36SystemChat.h"

void Day36SystemChat::Init()
{
	Super::Init();
	_objectId = StaticObjectId++;


	//이벤트 구독
	GET_SINGLE(GameEventManager)->GetEvent<int>(L"AppearBoss")->AddListen(this, &Day36SystemChat::OnEvent_AppearBoss);
	GET_SINGLE(GameEventManager)->GetEvent<int>(L"CharacterDied")->AddListen(this, &Day36SystemChat::OnEvent_CharacterDied);
}
void Day36SystemChat::Render(HDC hdc)
{
	Super::Render(hdc);
}
void Day36SystemChat::Update()
{
	Super::Update();
}
void Day36SystemChat::Release()
{
	Super::Release();
}

void Day36SystemChat::OnEvent_AppearBoss(int bossId)
{
	printf("[System] 보스가 등장하였습니다. 보스 번호 : %d\n", bossId);
}
void Day36SystemChat::OnEvent_CharacterDied(int characterId)
{
	printf("[System] 플레이어가 죽었습니다. 캐릭터 번호 : %d\n", characterId);
}