#include "pch.h"
#include "Day35Scene.h"
#include "Button.h"
#include "Sprite.h"
#include "GameResultPanel.h"
void Day35Scene::Init()
{
	Super::Init();

	Texture* texture = Resource->LoadTexture(L"T_Button", L"Day35/button.bmp");
	Resource->CreateSprite(L"S_Image_Normal", texture, 0, 0, 368, 98);
	Resource->CreateSprite(L"S_Image_Hover", texture, 0, 98, 368, 98);
	Resource->CreateSprite(L"S_Image_Pressed", texture, 0, 98 * 2, 368, 98);
	Resource->CreateSprite(L"S_Image_Disabled", texture, 0, 98 * 3, 368, 98);

	{
		Button* button = new Button();
		button->Init();
		button->SetPos({ WIN_SIZE_X / 2,WIN_SIZE_Y / 2 });
		Sprite* sprite = Resource->GetSprite(L"S_Image_Normal");
		button->SetSize(sprite->GetSize());
		button->SetSprite(EButtonState::Normal, Resource->GetSprite(L"S_Image_Normal"));
		button->SetSprite(EButtonState::Hover, Resource->GetSprite(L"S_Image_Hover"));
		button->SetSprite(EButtonState::Pressed, Resource->GetSprite(L"S_Image_Pressed"));
		button->SetSprite(EButtonState::Disabled, Resource->GetSprite(L"S_Image_Disabled"));

		this->AddUI(button);
	}
}

void Day35Scene::Render(HDC hdc)
{
	Super::Render(hdc);
	// 씬 이름 출력
	{
		wstring nameStr = ::format(L"Day35Scene");
		Draw::Text(hdc, 0, 20, nameStr);
	}

	{
		wstring str = ::format(L"Count : {}", _count);
		Draw::Text(hdc, WIN_SIZE_X - 100, 20, str);
	}
}
void Day35Scene::Update()
{
	Super::Update();
}
void Day35Scene::Release()
{
	Super::Release();
}
