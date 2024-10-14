#pragma once
#include <random>
#include <chrono>
class RanddomManager
{
	DECLARE_SINGLE(RandomManager);

public:
	void Init()
	{
		auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		_engine.seed(seed);
	}

	int GetInt(int min, int max)
	{
		std::uniform_int_distribution<int> dist(min, max);
	}

	double GetDouble(double min, double max)
	{

	}

	float GetFloat(float min, float max)
	{

	}

private:
	std::mt19937 _engine;
};

#define Random GET_SINGLE(RandomManager)
