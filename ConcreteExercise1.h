#pragma once
#define CONCRETEEXERCISE1_H

#include "Exercise.h"
#include <iostream>

namespace algebra
{
    
    /**
     * @brief Класс, реализующий конкретное упражнение на основе матрицы и генератора.
     */
    template <typename T>
    class ConcreteExercise1 : public Exercise<T>
    {
    public:
        
        /**
         * @brief Конструктор класса ConcreteExercise.
         * @param matrix Матрица для упражнения.
         * @param generator Генератор для заполнения матрицы и выполнения задач.
         */
        ConcreteExercise1(Matrix<T> matrix, Generator& generator);

        /**
         * @brief Реализация задачи 1.
         * @override
         */
        void task() override;

    };
}