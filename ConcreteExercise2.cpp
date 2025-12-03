#include "ConcreteExercise2.h"
#include <iostream>
#include <limits>
using namespace std;
namespace algebra
{

	template <typename T>
	ConcreteExercise2<T>::ConcreteExercise2(Matrix<T> matrix, Generator& generator) : Exercise<T>(matrix, generator) {}

	template <typename T>
	void ConcreteExercise2<T>::task()
	{
		int k;
		cout << "Введите число К: ";
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

	template class ConcreteExercise2<int>;


}
