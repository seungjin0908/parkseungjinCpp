#include "pch.h"
#include "Button.h"
#include "Panel.h"
#include "Sprite.h"

void Button::Init()
{
	Super::Init();

	this->SetState(EButtonState::Normal);
}
void Button::Render(HDC hdc)
{
	if (_isShow == false)
	{
		return;
	}
	Super::Render(hdc);

	if (_currentSprite = nullptr)
	{
		return;
	}

	Panel* parent = this->GetParent();
	Vector2 renderPos = { _pos.x,_pos.y };
	while (parent != nullptr)
	{
		renderPos += parent->GetPos();
		parent = parent->GetParent();
	}

	_currentSprite->Render(hdc, renderPos.x, renderPos.y);
}
void Button::Update()
{
	Super::Update();

	// 버튼의 특성
	// 버튼위에 마우스가 있으면 Hover상태로 보여준다.
	// 버튼위에 마우스가 있고 + 클릭상태면 Pressed로 보여준다.
	// Disabled면 그냥 Disabled로 보여준다.
	// 그 외에는 Normal 상태

	// 수도코드
	// 
	//if (상태 == disabled)
	//{
	//	SetState(disabled);
	//	return;
	//}

	//if (마우스가 내 버튼안에 있으면)
	//{
	//	if (내가 현재 클릭중인 상태라면)
	//	{
	//		SetState(pressed);
	//	}
	//	else
	//	{
	//		// 클릭하다 떼어냈다면?
	//		if (state == pressed)
	//		{
	//			// 원하는 함수실행
	//		}
	//		SetState(hover);
	//	}
	//}
	//else
	//{
	//	SetState(normal);
	//}

	if (_state == EButtonState::Disabled)
	{
		SetState(EButtonState::Disabled);
		return;
	}

	if (IsInMouse())
	{
		if (Input->GetKey(KeyCode::LeftMouse) || Input->GetKey(KeyCode::RightMouse))
		{
			SetState(EButtonState::Pressed);
		}
		else
		{
			if (_state == EButtonState::Pressed)
			{
				//TODO : 원하는 함수실행
				printf("Pressed!\n");

				if (_onclick != nullptr)
				{
					_onclick();
				}
			}
			SetState(EButtonState::Hover);
		}
	}
	else
	{
		SetState(EButtonState::Normal);
	}
}
void Button::Release()
{
	Super::Release();
}

void Button::SetState(EButtonState state)
{
	_state = EButtonState::Normal;
	_currentSprite = _sprites[(int)_state];
}
