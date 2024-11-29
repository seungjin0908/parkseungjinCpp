#include "pch.h"
#include "ScorePanel.h"
#include "Image.h"
void ScorePanel::Init()
{
	Super::Init();

	Resource->LoadTexture(L"T_Image_Background", L"Day35/Image_Star_Fill.bmp", RGB(255, 0, 255));
	Resource->CreateSprite(L"S_Image_Background", Resource->GetTexture(L"T_Image_Star_Fill"));

	{
		Image* image = new Image();
		image->Init();
		image->SetPos({ 0,0 });
		image->SetSprite(Resource->GetSprite(L"S_Image_Star_Fill"));
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