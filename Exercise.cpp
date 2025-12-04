#include "Exercise.h"

namespace algebra
{

	template <typename T>
	Exercise<T>::Exercise(const Matrix<T>& matrix, Generator& generator) : matrix(matrix), generator(generator) {}

	template class Exercise<int>;

}
