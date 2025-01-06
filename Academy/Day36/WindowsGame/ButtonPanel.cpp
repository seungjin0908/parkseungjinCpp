#include "pch.h"
#include "ButtonPanel.h"
#include "Button.h"
#include "Day35Scene.h"
#include "Sprite.h"
void ButtonPanel::Init()
{
	Super::Init();
	{
		Texture* texture = Resource->LoadTexture(L"T_Button1", L"Day35/button1.bmp");
		Resource->CreateSprite(L"S_Button1_Normal", texture, 0, 0, 363, 98);
		Resource->CreateSprite(L"S_Button1_Hover", texture, 0, 98, 363, 98);
		Resource->CreateSprite(L"S_Button1_Pressed", texture, 0, 98 * 2, 363, 98);
		Resource->CreateSprite(L"S_Button1_Disabled", texture, 0, 98 * 3, 363, 98);
	}
	{
		Texture* texture = Resource->LoadTexture(L"T_Button2", L"Day35/button2.bmp");
		Resource->CreateSprite(L"S_Button2_Normal", texture, 0, 0, 363, 98);
		Resource->CreateSprite(L"S_Button2_Hover", texture, 0, 98, 363, 98);
		Resource->CreateSprite(L"S_Button2_Pressed", texture, 0, 98 * 2, 363, 98);
		Resource->CreateSprite(L"S_Button2_Disabled", texture, 0, 98 * 3, 363, 98);
	}
	{
		Button* button = new Button();
		button->Init();
		button->AddOnClickDelegate(dynamic_cast<Day35Scene*>(CurrentScene), 
			&Day35Scene::AddCount);
		button->SetPos({ 0, 0 });
		Sprite* sprite = Resource->GetSprite(L"S_Button1_Normal");
		button->SetSize(sprite->GetSize());
		button->SetSprite(EButtonState::Normal, Resource->GetSprite(L"S_Button1_Normal"));
		button->SetSprite(EButtonState::Hover, Resource->GetSprite(L"S_Button1_Hover"));
		button->SetSprite(EButtonState::Pressed, Resource->GetSprite(L"S_Button1_Pressed"));
		button->SetSprite(EButtonState::Disabled, Resource->GetSprite(L"S_Button1_Disabled"));
		
		this->AddChild(button);
	}

	{
		Button* button = new Button();
		button->Init();
		button->AddOnClickDelegate(dynamic_cast<Day35Scene*>(CurrentScene),
			&Day35Scene::AddCount);
		button->SetPos({ 0, 100 });
		Sprite* sprite = Resource->GetSprite(L"S_Button2_Normal");
		button->SetSize(sprite->GetSize());
		button->SetSprite(EButtonState::Normal, Resource->GetSprite(L"S_Button2_Normal"));
		button->SetSprite(EButtonState::Hover, Resource->GetSprite(L"S_Button2_Hover"));
		button->SetSprite(EButtonState::Pressed, Resource->GetSprite(L"S_Button2_Pressed"));
		button->SetSprite(EButtonState::Disabled, Resource->GetSprite(L"S_Button2_Disabled"));

		this->AddChild(button);
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