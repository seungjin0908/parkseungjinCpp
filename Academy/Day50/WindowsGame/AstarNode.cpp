#include "pch.h"
#include "AstarNode.h"
#include "Vector2Int.h"
bool AstarNode::operator<(const AstarNode& other) const
{
	return G + H < other.G + other.H;
}

bool AstarNode::operator>(const AstarNode& other) const
{
	return G + H > other.G + other.H;
}