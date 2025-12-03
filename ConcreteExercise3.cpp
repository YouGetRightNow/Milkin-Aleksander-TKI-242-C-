#include "ConcreteExercise3.h"
#include <iostream>
#include <limits>
using namespace std;
namespace algebra
{

	template <typename T>
	ConcreteExercise3<T>::ConcreteExercise3(Matrix<T> matrix, Generator& generator) : Exercise<T>(matrix, generator) {}

	template <typename T>
	void ConcreteExercise3<T>::task()
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

	template class ConcreteExercise3<int>;

}