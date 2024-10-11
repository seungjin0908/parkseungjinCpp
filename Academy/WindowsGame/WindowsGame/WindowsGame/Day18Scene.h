#pragma once
#include "Scene.h"

enum class Day18SceneState
{
	Ready,
	Play,
	None
};
class Day18Scene : public Scene
{
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	void Update_Ready();
	void Update_Play();

public:
	void Update_Default();

private:
	CenterRect _ball = {};
	CenterRect _leftWall = {};
	CenterRect _rightWall = {};

	int _playerScore = 0;
	int _comScore = 0;

	Day18SceneState _state = Day18SceneState::None;
	bool _ballPosIsLeftWall = true;

	float _wallSpeed = 500;
	bool _isrightWallMoveDirTop = true;

	Vector2 _ballDir = {};
	float _ballSpeed = 1000;
};

