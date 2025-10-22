#include "ConcreteExercise.h"
#include <iostream>
#include <limits>
using namespace std;
namespace algebra
{

    template <typename T>
    ConcreteExercise<T>::ConcreteExercise(Matrix<T> matrix, Generator& generator) : Exercise<T>(matrix, generator) {}

    template <typename T>
    void ConcreteExercise<T>::task1()
    {
        if (this->matrix.getSize() > 0 && this->matrix[0] % 5 == 0)
        {
            this->matrix[0] = 0;
        }
    }

    template <typename T>
    void ConcreteExercise<T>::task2()
    {
        int k;
        cout << "Введите число K дл¤ вставки:  ";
        cin >> k;

        size_t originalSize = this->matrix.getSize();
        T* newData = new T[originalSize * 2];
        size_t newSize = 0;

        for (size_t i = 0; i < originalSize; ++i)
        {
            newData[newSize++] = this->matrix[i];

            if (this->matrix[i] % 2 != 0)
            {
                T temp = this->matrix[i];
                while (temp >= 10)
                {
                    temp /= 10;
                }
                if (temp == k)
                {
                    newData[newSize++] = static_cast<T>(k);
                }
            }
        }

        Matrix<T> newMatrix(newSize);
        for (size_t i = 0; i < newSize; ++i) 
        {
            newMatrix[i] = newData[i];
        }

        delete[] newData;
        this->matrix = move(newMatrix);
    }

    template <typename T>
    void ConcreteExercise<T>::task3()
    {
        size_t size = this->matrix.getSize();
        if (size == 0) return;

        Matrix<T> tempMatrix(size);
        for (size_t i = 0; i < size; ++i)
        {
            tempMatrix[i] = this->matrix[i];
        }

        this->matrix[0] = 0;
        if (size > 1) 
        {
            this->matrix[size - 1] = 0;
        }
        for (size_t i = 1; i < size - 1; ++i)
        {
            this->matrix[i] = tempMatrix[i] * static_cast<T>(i + 1);
        }
    }

    template class ConcreteExercise<int>;


}
