#include "pch.h"
#include "ProfileAreaPanel.h"

void ProfileAreaPanel::Init()
{
	Super::Init();

	Resource->LoadTexture(L"T_ProfileImage", L"Day34/Image_Profile.bmp", RGB(255, 255, 255));
	Resource->CreateSprite(L"S_ProfileImage", Resource->GetTexture(L"T_ProfileImage"));
	Resource->LoadTexture(L"T_PlusImage", L"Day34/Image_Plus.bmp", RGB(255, 255, 255));
	Resource->CreateSprite(L"S_PlusImage", Resource->GetTexture(L"T_PlusImage"));
}

void ProfileAreaPanel::Render(HDC hdc)
{
	Super::Render(hdc);
}

void ProfileAreaPanel::Update()
{
	Super::Update();
}

void ProfileAreaPanel::Release()
{
	Super::Release();
}
