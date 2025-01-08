#include "pch.h"
#include "UI.h"
#include "Panel.h"

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

//다른 프로그래머 입장 (컨텐츠프로그래머)
// SetIsShow << 뭔가 건들이기 무섭습니다.
// Show, Hide로 되어있는 함수들은 
// 직관적이고 아 이함수를 쓰면 나오겠구나.

//  + virtual 함수이기때문에. 추가적인 효과도 줄수있습니다.
// 이 UI 가 나올떄 이펙트가 같이나왔으면 좋겠다.
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
	// _pos, _size기준으로 마우스에 있는지정도만 체크해도 됩니다.

	Panel* parent = this->GetParent();
	Vector2 renderPos = { _pos.x, _pos.y };
	while (parent != nullptr)
	{
		renderPos += parent->GetPos();
		parent = parent->GetParent();
	}

	CenterRect centerRect = CenterRect(renderPos.x, renderPos.y,
		static_cast<float>(_size.x), static_cast<float>(_size.y));


	return Collision::PtInRect(Input->GetMousePos(), centerRect.ToRect());
}