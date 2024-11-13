#pragma once
#include "Vector2Int.h"
struct AstarNode
{
	Vector2Int Vertex;
	float G;
	float H;

	bool operator<(const AstarNode& other)const
	{
		return G + H < other.G + other.H;
	}

	bool operator>(const AstarNode& other)const
	{
		return G + H > other.G + other.H;
	}
};

