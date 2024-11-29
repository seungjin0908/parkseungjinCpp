#pragma once
#include "UI.h"

class Sprite;
enum class EButtonState
{
	Hover, Pressed, Normal, Disabled, End
};
class Button : public UI
{
<<<<<<< HEAD
	DECLARE_CHILD(Button, UI)
=======
	DECLARE_CHILD(Button, UI);
>>>>>>> a40139de517a68c5574ed6859716746e43b829fe

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
<<<<<<< HEAD
	// function<void()> 이 변수를 만들어서 보내야하기 떄문에, 사용자 측면에서 많이 불편합니다.
	/*void AddOnClickDelegate(function<void()> onclick)
=======
	// function<void()> 이 변수를 만들어서 보내야 하기 때문에, 사용자 측면에서 많이 불편하다.
	/*void AddOnClickDelegate(function<void()>onclick)
>>>>>>> a40139de517a68c5574ed6859716746e43b829fe
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

<<<<<<< HEAD
	//버튼 눌렀을때 이벤트를 받아주는 callbackfunction 변수
	function<void()> _onclick = nullptr;
=======
	// 버튼 눌렀을때 이벤트를 받아주는 callbackfunction 변수
	function<void()>_onclick = nullptr;
>>>>>>> a40139de517a68c5574ed6859716746e43b829fe
};

