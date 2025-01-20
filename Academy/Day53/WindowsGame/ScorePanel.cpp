#include "pch.h"
#include "ScorePanel.h"
#include "Image.h"
void ScorePanel::Init()
{
	Super::Init();

	Resource->LoadTexture(L"T_Image_ScoreBackground", L"Day35/Image_ScoreBackground.bmp", RGB(255, 0, 255));
	Resource->CreateSprite(L"S_Image_ScoreBackground", Resource->GetTexture(L"T_Image_ScoreBackground"));


	{
		Image* image = new Image();
		image->Init();
		image->SetPos({ 0, 0 });
		image->SetSprite(Resource->GetSprite(L"S_Image_ScoreBackground"));
		this->AddChild(image);
	}
}
void ScorePanel::Render(HDC hdc)
{
	Super::Render(hdc);
}
void ScorePanel::Update()
{
	Super::Update();
}
void ScorePanel::Release()
{
	Super::Release();
}