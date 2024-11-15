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
	void Update_Idle();
	void Update_Move();

public:
	void SetFlipbook();

	inline virtual void SetPos(Vector2 pos) override { _body.pos = pos + Vector2(0, 30); }
	inline virtual void Vector2 GetPos()

	void SetTilePos(Vector2Int pos) { _tilePos = pos; }
	Vector2Int GetTilePos() { return _tilePos; }

public: // 움직임 관련
	void SetPath(vector<Vector2Int>paths);
	bool HasReachedDest();

private:
	Day27CreatureState _state = Day27CreatureState::Idle;
	Day27CreatureDir _dir = Day27CreatureDir::Down;
	FlipbookRenderer* _flipbookRenderer = nullptr;
	Vector2 _inputDir = {};
	Vector2Int _tilePos;

private:
	float _speed = 100.0f;
	vector<Vector2Int> _paths;
	int _pathIndex = 0;

};