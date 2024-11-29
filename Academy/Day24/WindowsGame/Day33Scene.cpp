#include "pch.h"
#include "Day33Scene.h"
void Day33Scene::Init()
{
	Super::Init();


	Resource->LoadSound(L"BGM_Day33Scene", L"Day33/Sounds/Test.wav");

	GET_SINGLE(SoundManager)->Play(L"BGM_Day33Scene", true);

}
void Day33Scene::Render(HDC hdc)
{
	Super::Render(hdc);
	//씬 이름 출력
	{
		wstring nameStr = ::format(L"Day33Scene");
		Draw::Text(hdc, 0, 20, nameStr);
	}
}
void Day33Scene::Update()
{
	Super::Update();

	if (Input->GetKeyDown(KeyCode::A))
	{
		GET_SINGLE(SoundManager)->Play(L"BGM_Day33Scene", true);
	}

	if (Input->GetKeyDown(KeyCode::S))
	{
		GET_SINGLE(SoundManager)->Stop(L"BGM_Day33Scene");
	}
}
void Day33Scene::Release()
{
	Super::Release();
}