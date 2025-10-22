#pragma once
#define CONCRETEEXERCISE_H

#include "Exercise.h"
#include <iostream>

namespace algebra
{
    
    /**
     * @brief Класс, реализующий конкретное упражнение на основе матрицы и генератора.
     */
    template <typename T>
    class ConcreteExercise : public Exercise<T>
    {
    public:
        
        /**
         * @brief Конструктор класса ConcreteExercise.
         * @param matrix Матрица для упражнения.
         * @param generator Генератор для заполнения матрицы и выполнения задач.
         */
        ConcreteExercise(Matrix<T> matrix, Generator& generator);

        /**
         * @brief Реализация задачи 1.
         * @override
         */
        void task1() override;

        /**
         * @brief Реализация задачи 2.
         * @override
         */
        void task2() override;

        /**
         * @brief Реализация задачи 3.
         * @override
         */
        void task3() override;
    };
}
