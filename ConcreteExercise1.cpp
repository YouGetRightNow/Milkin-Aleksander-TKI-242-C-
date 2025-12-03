#include "ConcreteExercise1.h"
#include <iostream>
#include <limits>
using namespace std;
namespace algebra
{

    template <typename T>
    ConcreteExercise1<T>::ConcreteExercise1(Matrix<T> matrix, Generator& generator) : Exercise<T>(matrix, generator) {}

    template <typename T>
    void ConcreteExercise1<T>::task()
    {
        if (this->matrix.getSize() > 0 && this->matrix[0] % 5 == 0)
        {
            this->matrix[0] = 0;
        }
    }

    template class ConcreteExercise1<int>;

}

