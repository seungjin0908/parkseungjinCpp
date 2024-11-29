#include "pch.h"
#include "Tilemap.h"
#include "GameObject.h"
#include "Sprite.h"

void Tilemap::SaveFile(const wstring& path)
{
	wofstream ofs;
	ofs.open(path);

	try
	{
		ofs << _mapSize.x << endl;
		ofs << _mapSize.y << endl;

		for (int y = 0; y < _mapSize.y; y++)
		{
			for (int x = 0; x < _mapSize.x; x++)
			{
				ofs << (_tiles[y][x].Value / 10) % 10;
				ofs << _tiles[y][x].Value % 10;
			}
			ofs << endl;
		}

		ofs.close();
	}
	catch (exception ex)
	{
		ofs.close();
	}

}
void Tilemap::LoadFile(const wstring& path)
{
	// 회사마다 보통 FileIO를 만들어두거든요
	// 이코드는 크게 참고안하셔도돼요.

	wifstream ifs;
	ifs.open(path);
	try
	{
		ifs >> _mapSize.x;
		ifs >> _mapSize.y;

		_tiles = vector<vector<Tile>>(_mapSize.y, vector<Tile>(_mapSize.x));


		for (int y = 0; y < _mapSize.y; y++)
		{
			//한줄씩
			wstring line;
			ifs >> line;

			for (int x = 0; x < _mapSize.x; x++)
			{
				// 두글자씩 끊어서 저장했죠

				int value10 = line[x * 2] - L'0';	// 0 ~ 9 
				int value1 = line[x * 2 + 1] - L'0';

				_tiles[y][x].Value = value10 * 10 + value1;
			}
		}

		ifs.close();
	}
	catch (exception ex)
	{

		ifs.close();
	}

}

void Tilemap::Render(HDC hdc, int x, int y)
{
	// 그림을 그릴때,
	// _tiles[y][x] 에 따라서 그림을 그리면 되는데
	// Tile Value에 따라서 어떤 스프라이트를 써야하는지는 정보가 없습니다.
	// _sprites 에 TileValue에 따라서 그릴 스프라이트를 넣어놨습니다.

	//_tiles
	// _mapSize

	int startX = 0, startY = 0;
	int endX = 0, endY = 0;

	Vector2Int screenSize = { WIN_SIZE_X , WIN_SIZE_Y };

	startX = max(-x / _tileSize.x, 0);
	startY = max(-y / _tileSize.y, 0);
	endX = min((screenSize.x - (x - _tileSize.x)) / _tileSize.x + 1, _mapSize.x);
	endY = min((screenSize.y - (y - _tileSize.y)) / _tileSize.y + 1, _mapSize.y);


	for (int my = startY; my < endY; my++)
	{
		for (int mx = startX; mx < endX; mx++)
		{
			// 1. Tile Value 가져오기
			int value = _tiles[my][mx].Value;

			if (_sprites.size() <= value)
				continue;

			// 2. 그려야하는 위치 확인
			Vector2Int renderPos = Vector2Int(
				x + mx * _tileSize.x,
				y + my * _tileSize.y
			);

			// 3. 해당 스프라이트 렌더
			_sprites[value]->Render(hdc, renderPos.x, renderPos.y);
		}
	}
}

void Tilemap::SetSprites(vector<Sprite*> sprites)
{
	_sprites = sprites;

	if (sprites.size() <= 0) return;


	_tileSize.x = sprites.back()->GetSize().x;
	_tileSize.y = sprites.back()->GetSize().y;
}


Vector2 Tilemap::GetTileWorldPosByTilePos(Vector2Int tilePos)
{
	Vector2 returnValue;
	returnValue.x = (tilePos.x + 0.5f) * this->GetTileSize().x;
	returnValue.y = (tilePos.y + 0.5f) * this->GetTileSize().y;

	return returnValue;
}
Vector2Int Tilemap::GetTilePosByWorldPos(Vector2 worldPos)
{
	Vector2Int returnValue;
	returnValue.x = static_cast<int>(worldPos.x / this->GetTileSize().x);
	returnValue.y = static_cast<int>(worldPos.y / this->GetTileSize().y);

	return returnValue;
}

vector<Vector2Int> Tilemap::Calculate_Astar(Vector2Int from, Vector2Int to)
{
	priority_queue<AstarNode, vector<AstarNode>, greater<AstarNode>> queue;

	Vector2Int dest = to;
	Vector2Int src = from;

	Vector2Int mapSize = this->GetMapSize();
	vector<vector<bool>> visited = vector<vector<bool>>(mapSize.y, vector<bool>(mapSize.x, false));
	vector<vector<Vector2Int>> parents = vector<vector<Vector2Int>>(mapSize.y, vector<Vector2Int>(mapSize.x, { -1, -1 }));
	vector<vector<float>> best = vector<vector<float>>(mapSize.y, vector<float>(mapSize.x, 9999999));

	// 시작값 세팅
	{
		AstarNode node;
		node.Vertex = src;
		node.G = 0;
		node.H = (to - node.Vertex).Length();

		queue.push(node);
	}

	while (false == queue.empty())
	{
		AstarNode node = queue.top();
		queue.pop();

		//------------------------------
		//	1. 방문했다 체크
		//------------------------------
		visited[node.Vertex.y][node.Vertex.x] = true;

		//------------------------------
		//	2. 현재 지점이 dest면 탈출
		//------------------------------
		if (node.Vertex == dest)
		{
			break;
		}

		//------------------------------
		//	3. 갈수있는곳 모두 추가
		//------------------------------
		// 1) 변수세팅
		Vector2Int front[4] =
		{
			Vector2Int(0, -1),		// UP
			Vector2Int(1, 0),		// RIGHT
			Vector2Int(0, 1),		// DOWN
			Vector2Int(-1, 0)		// LEFT
		};

		int moveCost[4] =
		{
			1,		// UP
			1,		// RIGHT
			1,		// DOWN
			1,		// LEFT
		};

		// 2) 갈수있는 방향 for문
		for (int i = 0; i < 4; i++)
		{
			Vector2Int nextPos = node.Vertex + front[i];

			//갈수있는 지형이고, 방문한적 없으면
			if (CanGo(node.Vertex, nextPos) && visited[nextPos.y][nextPos.x] == false)
			{
				//큐에 추가할수있는지 확인해보기
				AstarNode newNode;
				newNode.G = node.G + moveCost[i];
				newNode.H = (dest - newNode.Vertex).Length();
				newNode.Vertex = nextPos;

				//현재 베스트보다 작아야만 넣을수 있음.
				if (newNode.G + newNode.H < best[nextPos.y][nextPos.x])
				{
					queue.push(newNode);
					best[nextPos.y][nextPos.x] = newNode.G + newNode.H;
					parents[nextPos.y][nextPos.x] = node.Vertex;
				}
			}
		}
	}

	// 리스트에 담아서 리턴
	vector<Vector2Int> path;
	Vector2Int pos = dest;

	//못찾았으면 빈상태로 리턴.
	if (visited[dest.y][dest.x] == false)
		return path;

	while (true)
	{
		path.push_back(pos);

		if (pos == src)
		{
			break;
		}

		pos = parents[pos.y][pos.x];
	}

	reverse(path.begin(), path.end());

	return path;
}

bool Tilemap::CanGo(Vector2Int from, Vector2Int to)
{
	if (to.x < 0)
		return false;

	if (this->GetMapSize().x <= to.x)
		return false;

	if (to.y < 0)
		return false;

	if (this->GetMapSize().y <= to.y)
		return false;


	Tile toTile = this->GetTileAt(to);

	vector<int> moveableTileList = { 3, 11, 12 };

	//갈수없는 지형이라면
	if (moveableTileList.end() == find(moveableTileList.begin(), moveableTileList.end(), toTile.Value))
	{
		return false;
	}

	return true;
}