#include "pch.h"
#include "Day18Scene.h"

void Day18Scene::Init()
{
	_ball = CenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y / 2, 20, 20);
	_leftWall = CenterRect::MakeLTWH(0, WIN_SIZE_Y / 2 - 150, 30, 300);
	_rightWall = CenterRect::MakeLTWH(WIN_SIZE_X - 30, WIN_SIZE_Y / 2 - 150, 30, 300);

	_state = Day18SceneState::Ready;
	_ballPosIsLeftWall = true;
}
void Day18Scene::Render(HDC hdc)
{
	//씬 이름 출력
	{
		wstring nameStr = ::format(L"Day18Scene");
		Draw::Text(hdc, 0, 20, nameStr);
	}

	_ball.Draw(hdc);
	_leftWall.Draw(hdc);
	_rightWall.Draw(hdc);

	{
		wstring scoreStr = ::format(L"{} : {}", (int)_playerScore, _comScore);
		Draw::Text(hdc, WIN_SIZE_X - 100, 0, scoreStr);
	}
}
void Day18Scene::Update()
{
	switch (_state)
	{
	case Day18SceneState::Ready:
		Update_Ready;
		break;
	case Day18SceneState::Play:
		Update_Play;
		break;
	case Day18SceneState::None:
		break;
	default:
		break;
	}
}
void Day18Scene::Release()
{
}

void Day18Scene::Update_Default()
{
	if (Input->GetKey(KeyCode::W))
	{
		_leftWall.pos.y -= 300 * Time->GetDeltaTime();
	}

	if (Input->GetKey(KeyCode::S))
	{
		_leftWall.pos.y += _wallSpeed * Time->GetDeltaTime();

		_leftWall.pos.y = ::clamp(_leftWall.pos.y,
			0 + _leftWall.height / 2,
			WIN_SIZE_Y - _leftWall.height / 2);
	}

	if (_isrightWallMoveDirTop)
	{
		_rightWall.pos.y -= _wallSpeed * Time->GetDeltaTime();

		if (_rightWall.Top() < 0)
		{
			_isrightWallMoveDirTop = false;
		}
	}
	else
	{
		_rightWall.pos.y += _wallSpeed * Time->GetDeltaTime();

		if (WIN_SIZE_Y < _rightWall.Bottom())
		{
			_isrightWallMoveDirTop = false;
		}
	}
}

void Day18Scene::Update_Ready()
{
	if (_ballPosIsLeftWall)
	{
		_ball.pos = Vector2(_leftWall.pos.x + _leftWall.width / 2 + _ball.width / 2,
			_leftWall.pos.y);
	}
	else
	{
		_ball.pos = Vector2
		(
			_rightWall.pos.x - _rightWall.width / 2 + _ball.width / 2,
			_rightWall.pos.y
		);
	}

	if (_ballPosIsLeftWall)
	{
		if (Input->GetKeyDown(KeyCode::RightMouse))
		{
			_ballDir = Vector2(Input->GetMousePos()) - _ball.pos;

			_ballDir = _ballDir.Normalize();

			_state = Day18SceneState::Play;
		}
	}
	else
	{
		_ballDir = Vector2(rand() % WIN_SIZE_X, rand() % WIN_SIZE_Y) - _ballDir;
		_ballDir = _ballDir.Normalize();
		_state = Day18SceneState::Play;
	}
}

void Day18Scene::Update_Play()
{
	_ball.pos += _ballDir * _ballSpeed * Time->GetDeltaTime();

	if (_ball.Top() < 0)
	{
		_ball.pos -= _ballDir * _ballSpeed * Time->GetDeltaTime();
		_ballDir.Reflect(Vector2::Down());
	}
	else if (WIN_SIZE_Y < _ball.Bottom())
	{
		_ball.pos -= _ballDir * _ballSpeed * Time->GetDeltaTime();
		_ballDir.Reflect(Vector2::Up());
	}

	if (Collision::RectInRect(_leftWall, _ball))
	{
		_ball.pos -= _ballDir * _ballSpeed * Time->GetDeltaTime();
		_ballDir.Reflect(Vector2::Right());
	}

	if (Collision::RectInRect(_rightWall, _ball)&& _ball.pos.x <_rightWall.Left())
	{
		_ball.pos -= _ballDir * _ballSpeed * Time->GetDeltaTime();
		_ballDir.Reflect(Vector2::Left());
	}

	if (_ball.Left() < 0)
	{
		_comScore++;
		_state = Day18SceneState::Ready;
		_ballPosIsLeftWall = true;
	}

	if (WIN_SIZE_X < _ball.Right())
	{
		_playerScore++;
		_state = Day18SceneState::Ready;
		_ballPosIsLeftWall = false;
	}
}

