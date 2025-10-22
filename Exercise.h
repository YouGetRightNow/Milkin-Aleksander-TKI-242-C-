#pragma once
#define EXERCISE_H
#include "Matrix.h"
#include "Generator.h"

namespace algebra
{
    /**
     * @brief Абстрактный базовый класс для упражнений, содержащих матрицу и генератор.
     */
    template <typename T>
    class Exercise
    {
    protected:
        
        /**
         * @brief Матрица, используемая в упражнении.
         */
        Matrix<T> matrix;

        /**
         * @brief Генератор случайных чисел, используемый в упражнении.
         */
        Generator& generator;

    public:
        
        /**
         * @brief Конструктор класса Exercise.
         * @param matrix Матрица, используемая в упражнении.
         * @param generator Генератор случайных чисел, используемый в упражнении.
         */
        Exercise(Matrix<T> matrix, Generator& generator);

        /**
         * @brief Виртуальный деструктор.
         */
        virtual ~Exercise() = default;

        /**
         * @brief Первая задача (абстрактный метод).
         */
        virtual void task1() = 0;

        /**
         * @brief Вторая задача (абстрактный метод).
         */
        virtual void task2() = 0;

        /**
         * @brief Третья задача (абстрактный метод).
         */
        virtual void task3() = 0;

        /**
         * @brief Возвращает ссылку на матрицу.
         * @return Ссылка на матрицу.
         */
        Matrix<T>& getMatrix();
    };

    template <typename T>
    
    /**
     * @brief Возвращает ссылку на матрицу.
     * @return Ссылка на матрицу.
     */
    inline Matrix<T>& Exercise<T>::getMatrix()
    {
        return matrix;
    }
}