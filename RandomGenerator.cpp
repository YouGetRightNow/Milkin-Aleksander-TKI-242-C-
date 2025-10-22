#include "RandomGenerator.h"

namespace algebra 
{
    RandomGenerator::RandomGenerator() 
        : distribution(-1000, 1000), generator(std::random_device{}())
    {
    }

    int RandomGenerator::generate()
    {
        return distribution(generator);
    }
}