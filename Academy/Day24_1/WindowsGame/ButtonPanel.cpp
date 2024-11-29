#include "pch.h"
#include "ButtonPanel.h"
void ButtonPanel::Init()
{
	Super::Init();
	{
		Texture* texture = Resource->LoadTexture(L"T_Button1", L"Day35/T_Button.bmp", RGB(255, 0, 255));
	}
}
void ButtonPanel::Render(HDC hdc)
{
	Super::Render(hdc);
}
void ButtonPanel::Update()
{
	Super::Update();
}
void ButtonPanel::Release()
{
	Super::Release();
}