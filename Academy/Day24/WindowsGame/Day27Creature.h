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

	// Offset 설정을 위해 override
	inline virtual void SetPos(Vector2 pos) override { _body.pos = pos ; }

	void SetTilePos(Vector2Int pos) { _tilePos = pos; }
	Vector2Int GetTilePos() { return _tilePos; }

	
public: // 움직임 관련
	void SetPath(vector<Vector2> paths);
	bool HasReachedDest();

private:
	Day27CreatureState _state = Day27CreatureState::Idle;
	Day27CreatureDir _dir = Day27CreatureDir::Down;
	FlipbookRenderer* _flipbookRenderer = nullptr;
	Vector2 _inputDir = {};
	Vector2Int _tilePos;
	wstring _currentFilpbookName;

private: // 움직임 관련
	float _speed = 100.0f;
	vector<Vector2> _paths;
	int _pathIndex = 0;
};

