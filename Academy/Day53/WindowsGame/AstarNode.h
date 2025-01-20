#pragma once
struct Vector2Int;
struct AstarNode
{
	Vector2Int Vertex;
	float G;	//여태까지 걸어온 양
	float H;	//목적지까지 남은 예상비용

	bool operator<(const AstarNode& other) const;
	bool operator>(const AstarNode& other) const;
};

