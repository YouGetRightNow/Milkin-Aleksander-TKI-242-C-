#pragma once
#define GENERATOR_H

namespace algebra
{
    /**
     * @brief Абстрактный базовый класс для генераторов случайных чисел.
     */
    class Generator
    {
    public:
        
        /**
         * @brief Виртуальный деструктор.
         */
        virtual ~Generator() = 0;

        /**
         * @brief Абстрактный метод для генерации случайного числа.
         * @return Сгенерированное случайное число.
         */
        virtual int generate() = 0;
    };
}