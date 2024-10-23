#include "pch.h"
#include "Day24Scene.h"

void Day24Scene::Init()
{
	Super::Init();
}

void Day24Scene::Render(HDC hdc)
{
	Super::Render(hdc);

	{
		wstring nameStr = ::format(L"Day24Scene");
	}
}

void Day24Scene::Update()
{
	Super::Update();
}

void Day24Scene::Release()
{
	Super::Release();
}
