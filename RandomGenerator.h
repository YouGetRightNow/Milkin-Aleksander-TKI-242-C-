#pragma once
#define RANDOMGENERATOR_H
#include "Generator.h"
#include <random>

using namespace std;
namespace algebra
{
    /**
     * @brief Класс, реализующий генератор случайных чисел в заданном диапазоне.
     */
    class RandomGenerator : public Generator
    {
    private:
        
        uniform_int_distribution<int> distribution;
        mt19937 generator;                           

    public:
       
        /**
         * @brief Конструктор RandomGenerator
         */
        RandomGenerator();

        /**
         * @brief Генерирует случайное число в заданном диапазоне.
         * @return Сгенерированное целое число.
         * @override
         */
        int generate() override;
    };
}
