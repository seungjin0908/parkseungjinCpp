#include "pch.h"
#include "Player.h"
#include "Board.h"
#include <queue>
#include <stack>
void Player::Init(Board* board)
{
	_board = board;
	
	_pos = board->GetStartPos();

	CalulatePath_RightHand();

	_currentIndex = 0;
}
void Player::Update()
{
	_currentIndex
}

bool Player::CanGo(int x, int y)
{
	int size = _board.GetSize();

	return false;
}

void Player::CalulatePath_RightHand()
{
	Vector2Int pos = _pos;
	_dir = EDir::Down;

	_path.clear();
	_path.push_back(pos);

	Vector2Int dest = _board->GetExitPos();

	Vector2Int front[4] =
	{
		Vector2Int(-1,0)	// Left
		,Vector2Int(0,-1)	// Up
		,Vector2Int(1,0)	// Right
		,Vector2Int(0,1)	// Down
	};

	while (pos != dest)
	{
		// 1. 현재 방향 기준으로, 오른쪽을 갈수 있는지 확인
		int newDir = ((int)_dir + 1) % 4;
		if (CanGo(pos + front[newDir]))
		{
			_dir = static_cast<EDir>(newDir);

			pos += front[newDir];

			_path.push_back(pos);
		}

		else if (CanGo(pos + front[(int)_dir]))
		{

			pos += front[(int)_dir];

			_path.push_back(pos);
		}
		else
		{
			int leftSideDir = ((int)_dir + 3) % 4;
			_dir = static_cast<EDir>(leftSideDir);
		}
	}
}

void Player::CalulatePath_BFS()
{
	Vector2Int pos = _pos;
	_dir = EDir::Down;

	_path.clear();
	_path.push_back(pos);

	Vector2Int dest = _board->GetExitPos();

	Vector2Int front[4] =
	{
		Vector2Int(-1,0)	// Left
		,Vector2Int(0,-1)	// Up
		,Vector2Int(1,0)	// Right
		,Vector2Int(0,1)	// Down
	};

	vector<vector<bool>>visited = vector<vector<bool>>(size, vector<bool>(size, false));
	vector<vector<Vector2Int>> parents=vector<Vector2Int>>(size, vector<Vector2Int>(size,)

	queue<Vector2Int> q;
	q.push(pos);

	while (false == q.empty())
	{
		pos = q.front();
		q.pop();
	}

	visited[pos.y][pos.x] = true;

	if (pos == dest)
		break;

	for (int i = 0; i < 4; i++)
	{
		Vector2Int nextPos = pos + front[i];

		if (visited[nextPos.y][nextPos.x] == true)
			continue;

		if (CanGo(nextPos) == false)
			continue;

		q.push(nextPos);
		parents[nextPos.y][nextPos.x] = pos;
	}

	//// 뒤집는 로직
	//for (int i = 0; i < _path.size() / 2; i++)
	//{
	//	int index1 = i;
	//	int index1 = _path.size() - 1 - i;

	//	Vector2Int temp = _path[index1];
	//}

	reverse(_path.begin(), _path.end());
}

void Player::CalulatePath_DFS()
{
	Vector2Int pos = _pos;
	_dir = EDir::Down;

	_path.clear();
	_path.push_back(pos);

	Vector2Int dest = _board->GetExitPos();

	int frontSize = 8;
	Vector2Int front[8] =
	{
		Vector2Int(-1,0)	// Left
		,Vector2Int(0,-1)	// Up
		,Vector2Int(1,0)	// Right
		,Vector2Int(0,1)	// Down
		,Vector2Int(-1,1)
		,Vector2Int(-1,-1)
		,Vector2Int(1,1)
		,Vector2Int(1,1)
	};

	vector<vector<bool>>visited = vector<vector<bool>>(size, vector<bool>(size, false));
	vector<vector<Vector2Int>> parents = vector<Vector2Int >> (size, vector<Vector2Int>(size, )

		queue<Vector2Int> q;
	q.push(pos);

	while (false == q.empty())
	{
		pos = q.front();
		q.pop();
	}

	visited[pos.y][pos.x] = true;

	if (pos == dest)
		break;

	for (int i = 0; i < 4; i++)
	{
		Vector2Int nextPos = pos + front[i];

		if (visited[nextPos.y][nextPos.x] == true)
			continue;

		if (CanGo(nextPos) == false)
			continue;

		q.push(nextPos);
		parents[nextPos.y][nextPos.x] = pos;
	}

	//// 뒤집는 로직
	//for (int i = 0; i < _path.size() / 2; i++)
	//{
	//	int index1 = i;
	//	int index1 = _path.size() - 1 - i;

	//	Vector2Int temp = _path[index1];
	//}

	reverse(_path.begin(), _path.end());
}
