#include "pch.h"
#include "UI.h"

void UI::Init()
{

}
void UI::Render(HDC hdc)
{
	if (_isShow == false)
	{
		return;
	}
}
void UI::Update()
{

}
void UI::Release()
{

}

// 다른 프로그래머 입장(컨텐츠프로그래머)
// SetIsShow << 뭔가 건들이기 무섭다.
// Show, Hide로 되어있는 함수들은
// 직관적이고 아 이함수를 쓰면 나오겠구나.

// + virtual 함수이기때문에, 추가적인 효과도 줄수있다.
// 이 UI가 나올때 이펙트가 같이 나왔으면 좋겠다.
void UI::Show()
{
	_isShow = true;
}
void UI::Hide()
{
	_isShow = false;
}

bool UI::IsInMouse()
{
	// _pos, _size 기준으로 마우스에 있는지 정도만 체크해도 된다.

	RECT rc = CenterRect(_pos.x, _pos.y,
		static_cast<float>(_size.x), static_cast<float>(_size.y));

	return Collision::PtInRect(Input->GetMousePos(),centerRect.)
	return false;
}
