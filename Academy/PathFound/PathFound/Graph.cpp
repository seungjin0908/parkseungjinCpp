#include "pch.h"
#include "Graph.h"
Graph Graph::MakeGraph(int type)
{
	Graph rv;

	if (type == 1)
	{
		for (int i = 0; i < 5; i++)
		{
			rv.vertexs.push_back(1);
		}
	}
	else if (type == 2)
	{

	}
	else if (type == 3)
	{

	}

	return rv;
}