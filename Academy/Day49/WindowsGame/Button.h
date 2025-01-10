#pragma once
#include "UI.h"

class Sprite;
enum class EButtonState
{
	Hover, Pressed, Normal, Disabled, End
};
class Button : public UI
{
	DECLARE_CHILD(Button, UI)

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	void SetState(EButtonState state);
	void SetSprite(EButtonState state, Sprite* sprite)
	{
		_sprites[(int)state] = sprite;
	}

public:
	// function<void()> 이 변수를 만들어서 보내야하기 떄문에, 사용자 측면에서 많이 불편합니다.
	/*void AddOnClickDelegate(function<void()> onclick)
	{
		_onclick = onclick;
	}*/

	template<typename T>
	void AddOnClickDelegate(T* owner, void(T::* func)())
	{
		_onclick = bind(func, owner);
	}

public:
	Sprite* _sprites[(int)EButtonState::End] = {};
	Sprite* _currentSprite = nullptr;

	EButtonState _state = EButtonState::Normal;

	//버튼 눌렀을때 이벤트를 받아주는 callbackfunction 변수
	function<void()> _onclick = nullptr;
};

