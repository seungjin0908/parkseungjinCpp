#include "pch.h"
#include "Day36Scene.h"
#include "Day36Boss.h"
#include "Day36Character.h"
#include "Day36FieldSystem.h"
#include "Day36SystemChat.h"

void Day36Scene::Init()
{
	Super::Init();

	//이벤트 생성
	{
		// 캐릭터 죽음 이벤트 등록
		GET_SINGLE(GameEventManager)->AddEvent(L"CharacterDied", new GameEvent<int>);

	}

	{
		// 보스 등장이벤트 등록
		GET_SINGLE(GameEventManager)->AddEvent(L"AppearBoss", new GameEvent<int>);

	}

	// 오브젝트 생성
	{
		GameObject* gameObject = new Day36Boss();
		gameObject->Init();
		this->SpawnGameObject(gameObject);
	}

	{
		GameObject* gameObject = new Day36Character();
		gameObject->Init();
		this->SpawnGameObject(gameObject);
	}

	{
		GameObject* gameObject = new Day36FieldSystem();
		gameObject->Init();
		this->SpawnGameObject(gameObject);
	}

	{
		GameObject* gameObject = new Day36SystemChat();
		gameObject->Init();
		this->SpawnGameObject(gameObject);
	}
}
void Day36Scene::Render(HDC hdc)
{
	Super::Render(hdc);
	//씬 이름 출력
	{
		wstring nameStr = ::format(L"Day36Scene");
		Draw::Text(hdc, 0, 20, nameStr);
	}
}
void Day36Scene::Update()
{
	Super::Update();

	if (Input->GetKeyDown(KeyCode::A))
	{
		printf("캐릭터 죽음 이벤트 발생\n");
	}

	if (Input->GetKeyDown(KeyCode::S))
	{
		printf("보스 등장 이벤트 발생\n");
	}
}
void Day36Scene::Release()
{
	{
		// 캐릭터 죽음 이벤트 등록
		GET_SINGLE(GameEventManager)->RemoveEvent(L"CharacterDied");

	}

	{
		// 보스 등장이벤트 등록
		GET_SINGLE(GameEventManager)->RemoveEvent(L"AppearBoss");

	}


	Super::Release();
}