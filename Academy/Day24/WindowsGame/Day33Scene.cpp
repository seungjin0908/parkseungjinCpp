#include "pch.h"
#include "Day33Scene.h"
void Day33Scene::Init()
{
	Super::Init();

	Resource->LoadSound(L"BGM_Day33Scene", L"Day33/Sounds/BGM.wav");


}

void Day33Scene::Render(HDC hdc)
{
	Super::Render(hdc);

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

	}
}

void Day33Scene::Release()
{
	Super::Release();
}
