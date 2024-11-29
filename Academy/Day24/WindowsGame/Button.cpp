#include "pch.h"
#include "Button.h"
#include "Panel.h"
#include "Sprite.h"

void Button::Init()
{
	Super::Init();

	this->SetState(EButtonState::Normal);
}
<<<<<<< HEAD

=======
>>>>>>> a40139de517a68c5574ed6859716746e43b829fe
void Button::Render(HDC hdc)
{
	if (_isShow == false)
	{
		return;
	}
	Super::Render(hdc);

<<<<<<< HEAD
	if (_currentSprite == nullptr)
=======
	if (_currentSprite = nullptr)
>>>>>>> a40139de517a68c5574ed6859716746e43b829fe
	{
		return;
	}

	Panel* parent = this->GetParent();
<<<<<<< HEAD
	Vector2 renderPos = { _pos.x, _pos.y };
=======
	Vector2 renderPos = { _pos.x,_pos.y };
>>>>>>> a40139de517a68c5574ed6859716746e43b829fe
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

<<<<<<< HEAD
	//버튼의 특성
	// 버튼위에 마우스가 있으면 Hover상태로 보여준다.
	// 버튼위에 마우스가 있고 + 클릭상태면 Pressed로 보여준다
	// Disabled면 그냥 Disabled로 보여준다.
	// 그 외에는 Normal 상태 
=======
	// 버튼의 특성
	// 버튼위에 마우스가 있으면 Hover상태로 보여준다.
	// 버튼위에 마우스가 있고 + 클릭상태면 Pressed로 보여준다.
	// Disabled면 그냥 Disabled로 보여준다.
	// 그 외에는 Normal 상태
>>>>>>> a40139de517a68c5574ed6859716746e43b829fe

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
<<<<<<< HEAD
	//		//클릭하다 떼어냈다면?
=======
	//		// 클릭하다 떼어냈다면?
>>>>>>> a40139de517a68c5574ed6859716746e43b829fe
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
<<<<<<< HEAD
=======

>>>>>>> a40139de517a68c5574ed6859716746e43b829fe
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
<<<<<<< HEAD

=======
>>>>>>> a40139de517a68c5574ed6859716746e43b829fe
}
void Button::Release()
{
	Super::Release();
}

void Button::SetState(EButtonState state)
{
<<<<<<< HEAD
	_state = state;
	_currentSprite = _sprites[(int)_state];
}
=======
	_state = EButtonState::Normal;
	_currentSprite = _sprites[(int)_state];
}
>>>>>>> a40139de517a68c5574ed6859716746e43b829fe
