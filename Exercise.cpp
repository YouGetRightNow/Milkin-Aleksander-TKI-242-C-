#include "Exercise.h"

namespace algebra
{

	template <typename T>
	Exercise<T>::Exercise(Matrix<T> matrix, Generator& generator) : matrix(matrix), generator(generator) {}

	template class Exercise<int>;

}