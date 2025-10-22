#pragma once
#define ISTREAMGENERATOR_H
#include "Generator.h"
#include <iostream>

using namespace std;
namespace algebra
{
    /**
     * @brief Класс, реализующий генератор случайных чисел, получающий значения из входного потока.
     */
    class IStreamGenerator : public Generator
    {
    private:
        
        /**
         * @brief Ссылка на входной поток, из которого будут считываться значения.
         */
        istream& in;

    public:
        /**
         * @brief Конструктор IStreamGenerator
         * @param in Входной поток (по умолчанию std::cin)
         */
        IStreamGenerator(istream& in = cin);

        /**
         * @brief Генерация значения из входного потока
         * @return Считанное целое число
         */
        int generate() override;
    };
}