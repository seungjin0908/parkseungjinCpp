#include "pch.h"
#include "GameResultPanel.h"
#include "Image.h"
void GameResultPanel::Init()
{
	Super::Init();

	Resource->LoadTexture(L"T_Image_Background",L"Day35/Image_")
}
void GameResultPanel::Render(HDC hdc)
{
	Super::Render(hdc);
}
void GameResultPanel::Update()
{
	Super::Update();
}
void GameResultPanel::Release()
{
	Super::Release();
}
