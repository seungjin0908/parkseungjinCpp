#include "pch.h"
#include "Day17Player.h"
void Day17Player::Init()
{
	_body = CenterRect(300, 100, 80, 80);
}
void Day17Player::Render(HDC hdc)
{
	_body.Draw(hdc);
}
void Day17Player::Update()
{
	if (InputManager::GetInstance()->GetKey(KeyCode::Left))
	{
		_body.pos.x -= _moveSpeed * Time->GetDeltaTime();
	}
	if (InputManager::GetInstance()->GetKey(KeyCode::Up))
	{
		_body.pos.y -= _moveSpeed * Time->GetDeltaTime();
	}
	if (InputManager::GetInstance()->GetKey(KeyCode::Right))
	{
		_body.pos.x += _moveSpeed * Time->GetDeltaTime();
	}
	if (InputManager::GetInstance()->GetKey(KeyCode::Down))
	{
		_body.pos.y += _moveSpeed * Time->GetDeltaTime();
	}

	RECT playerRect = _body.ToRect();
	CenterRect boxBody;
	RECT boxRect;
	RECT tmp;
	if (::IntersectRect(&tmp, &playerRect, &boxRect))
	{
		int width = tmp.right - tmp.left;
		int height = tmp.bottom - tmp.top;

		if (width < height)
		{
			if (playerRect.right == tmp.right)
			{
				boxBody.pos.x += width;
			}
			else if (playerRect.left == tmp.left)
			{
				boxBody.pos.x -= width;
			}
		}
		else
		{
			if (playerRect.top == tmp.top)
			{
				boxBody.pos.y -= height;
			}
			else if (playerRect.bottom == tmp.bottom)
			{
				boxBody.pos.y += height;
			}
		}
	}

	
}
void Day17Player::Release()
{

}
