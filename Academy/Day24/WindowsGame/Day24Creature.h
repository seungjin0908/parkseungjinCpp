#pragma once
#include "GameObject.h"

enum class Day24CreatureState
{
	Idle,
	Move,
	Attack
};

enum class Day24CreatureDir
{
	Up,
	Left,
	Right,
	Down
};
class FlipbookRenderer;
class Day24Creature : public GameObject
{
	DECLARE_CHILD(Day24Creature, GameObject);
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	void SetState(Day24CreatureState state);
	void SetDir(Day24CreatureDir dir);

	void SetFlipbook();

	void Update_Move();
	void Update_Idle();
private:
	Day24CreatureState _state = Day24CreatureState::Idle;
	Day24CreatureDir _dir = Day24CreatureDir::Down;
	FlipbookRenderer* _flipbookRenderer = nullptr;
	Vector2 _inputDir = {};

	bool _isAttacked = false;
	Vector2 _ShootDir = {};
};

