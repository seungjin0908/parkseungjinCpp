#pragma once
#include "GameObject.h"
enum class Day27CreatureState
{
	Idle,
	Move,
	Attack,
};

enum class Day27CreatureDir
{
	Up,
	Left,
	Right,
	Down,
};
class FlipbookRenderer;
class Day27Creature : public GameObject
{
	DECLARE_CHILD(Day27Creature, GameObject);

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	void SetFlipbook();

private:
	float _speed = 100.0f;
	Day27CreatureState _state = Day27CreatureState::Idle;
	Day27CreatureDir _dir = Day27CreatureDir::Down;
	
};

