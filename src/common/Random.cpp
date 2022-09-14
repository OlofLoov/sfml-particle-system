#include "Random.hpp"

std::mt19937 Random::s_twisterEngine;
std::uniform_int_distribution<uint32_t> Random::s_Distribution;
