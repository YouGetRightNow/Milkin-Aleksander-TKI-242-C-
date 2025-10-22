#pragma once
#define GENERATOR_H

namespace algebra
{
    /**
     * @brief јбстрактный базовый класс дл¤ генераторов случайных чисел.
     */
    class Generator
    {
    public:
        
        /**
         * @brief ¬иртуальный деструктор.
         */
        virtual ~Generator() = 0;

        /**
         * @brief јбстрактный метод дл¤ генерации случайного числа.
         * @return —генерированное случайное число.
         */
        virtual int generate() = 0;
    };
}
