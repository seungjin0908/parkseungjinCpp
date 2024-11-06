#include "pch.h"
#include "Board.h"
#include "Player.h"
void main()
{
	Board board;
	Player player;

	board.Init(&player);
	player.Init(&board);

	uint64 lastTick = 0;
	while (true)
	{
		const uint64 currentTick = ::GetTickCount64();
		const uint64 deltaTick = currentTick - lastTick;
		if (100 < deltaTick)
		{
			lastTick = currentTick;
			player.Update();
			board.Render();
		}
	}
}