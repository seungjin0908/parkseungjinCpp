#include "pch.h"
#include "Day48Scene.h"

void Day48Scene::Init()
{
	Super::Init();
}

void Day48Scene::Render(HDC hdc)
{
	Super::Render(hdc);
	//씬 이름 출력
	{
		wstring nameStr = ::format(L"Day48Scene");
		Draw::Text(hdc, 0, 20, nameStr);
	}
}
void Day48Scene::Update()
{
	Super::Update();
}
void Day48Scene::Release()
{
	Super::Release();
}