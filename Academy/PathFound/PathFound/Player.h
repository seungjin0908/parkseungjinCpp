#pragma once

enum class EDir
{
	Left = 0,
	Up,
	Right,
	Down,
	
};

class Player
{
public:
	void Init(Board* board);
	void Update();

	Vector2Int GetPos() { return _pos; }
	bool CanGo(int x, int y);
	bool CanGo(Vector2Int pos) { return CanGo(pos.x, pos.y); }

	void CalulatePath_RightHand();
	void CalulatePath_BFS();
	void CalulatePath_DFS();

public:
	Player() {}
	virtual ~Player() {}

private:
	Vector2Int _pos = {};
	EDir _dir = EDir::Right;

	Board * _board = nullptr;

	vector<>
};

