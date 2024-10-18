#pragma once

enum class SceneType
{
	None,
	DevScene,
	Day17Scene,
	Day18Scene,
	Day19Scene,
	Day21Scnen
};

enum class ColliderType
{
	None,
	Box,
	Circle
};

enum CollisionLayerType : uint8
{
	CLT_DEFAULT = 0,
	CLT_CREATURE,
	CLT_GROUND,
	CLT_ITEM
};