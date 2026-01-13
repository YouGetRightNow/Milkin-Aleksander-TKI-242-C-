#pragma once
#define MATRIX_H
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Generator.h"

using namespace std;
namespace algebra
{
    
    /**
     * @brief Класс, представляющий матрицу (одномерный массив).
     *
     * @tparam T Тип элементов матрицы.
     */
    template <typename T>
    class Matrix
    {
    private:

        /**
         * @brief Указатель на данные матрицы.
         */
        T* data;

        /**
         * @brief Размер матрицы.
         */
        size_t size;

    public:

        /**
         * @brief Конструктор по умолчанию.
         */
        Matrix();

        /**
         * @brief Конструктор, создающий матрицу заданного размера.
         * @param size Размер матрицы.
         */
        Matrix(const size_t size);

        /**
         * @brief Конструктор копирования.
         * @param other Объект, который копируется.
         */
        Matrix(const Matrix& other);

        /**
         * @brief Конструктор перемещения.
         * @param other Объект, который перемещается.
         */
        Matrix(Matrix&& other) noexcept;

        /**
         * @brief Деструктор.
         */
        ~Matrix();

        /**
         * @brief Оператор присваивания копированием.
         * @param other Объект, присваиваемый текущему.
         * @return Ссылка на текущий объект.
         */
        Matrix& operator=(const Matrix& other);

        /**
         * @brief Оператор присваивания перемещением.
         * @param other Объект, перемещаемый в текущий.
         * @return Ссылка на текущий объект.
         */
        Matrix& operator=(Matrix&& other) noexcept;

        /**
         * @brief Оператор доступа к элементу по индексу.
         * @param index Индекс элемента.
         * @return Ссылка на элемент матрицы.
         */
        T& operator[](const size_t index);

        /**
         * @brief Оператор доступа к элементу по индексу (константная версия).
         * @param index Индекс элемента.
         * @return Константная ссылка на элемент матрицы.
         */
        const T& operator[](const size_t index) const;

        /**
         * @brief Перегруженный оператор вывода в поток.
         * @param os Ссылка на выходной поток.
         * @param matrix Ссылка на матрицу.
         * @return Ссылка на выходной поток.
         */
        template<typename U>
        friend ostream& operator<<(ostream& os, const Matrix<U>& matrix);

        /**
         * @brief Перегруженный оператор ввода из потока.
         * @param is Ссылка на входной поток.
         * @param matrix Ссылка на матрицу.
         * @return Ссылка на входной поток.
         */
        template<typename U>
        friend istream& operator>>(istream& is,const Matrix<U>& matrix);

        /**
         * @brief Заполняет матрицу случайными числами с использованием генератора.
         * @param generator Ссылка на объект генератора.
         */
        void fill(const Generator& generator);

        /**
         * @brief Возвращает размер матрицы.
         * @return Размер матрицы.
         */
        size_t getSize() const;
    };

}

