#pragma once

#include <random>
#include <iostream>

// https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
class Random
{
public:
	static void init()
	{
		s_twisterEngine.seed(std::random_device()());
		s_Distribution = std::uniform_int_distribution<uint32_t>(1, std::numeric_limits<uint32_t>::max());
	}

	static float randomFloat()
	{
		return (float)s_Distribution(s_twisterEngine) / (float)std::numeric_limits<uint32_t>::max();
	}

private:
	static std::mt19937 s_twisterEngine;
	static std::uniform_int_distribution<uint32_t> s_Distribution;
};