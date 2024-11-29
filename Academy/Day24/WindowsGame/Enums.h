﻿#pragma once

enum class SceneType
{
	None,
	DevScene,
	Day17Scene,
	Day18Scene,
	Day19Scene,
	Day20Scene,
	Day21Scene,
	Day22Scene,
	Day23Scene,
	Day24Scene,
	Day26Scene,
	Day27Scene,
	Day33Scene,
	Day34Scene,
};

enum class ColliderType
{
	None,
	Box,
	Circle
};

enum CollisionLayerType
{
	CLT_DEFAULT = 0,
	CLT_CREATURE,
	CLT_GROUND,
	CLT_ITEM
};

// 뒤에 둘수록 마지막에 그린다.
enum class LayerType
{
	BackGround,
	Object,
	Character,
	WorldUI,



	End
};