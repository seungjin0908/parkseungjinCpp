#include "pch.h"
#include "PriorityQueue.h"

struct PQNode
{
	int x;
	int y;
	int cost;

	bool operator<(const PQNode& other) const
	{
		return cost < other.cost;
	}

	bool operator>(const PQNode& other) const
	{
		return cost > other.cost;
	}
};

void main()
{
	PriorityQueue<int> p;
	{
		PQNode node = { 1,1,3 };
	}

	/*p.Push(30);
	p.Push(50);
	p.Push(10);
	p.Push(5);
	p.Push(3);
	p.Push(1);
	p.Push(100);
	p.Push(300);
	p.Push(500);*/

	while (false == p.Empty())
	{
		cout << "Top : " << p.Peek() << endl;

		p.Pop();
	}
}