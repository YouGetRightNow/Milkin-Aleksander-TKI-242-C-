#include "Matrix.h"
#include "RandomGenerator.h"
#include "IStreamGenerator.h"
#include "ConcreteExercise1.h"
#include "ConcreteExercise2.h"
#include "ConcreteExercise3.h"
#include <iostream>
#include <string>
#include <locale.h>

using namespace std;
using namespace algebra;

enum class FillMethod {
	RANDOM = 1,
	MANUAL = 2
};

int main()
{
	setlocale(LC_ALL, "RU");

	size_t size;
	cout << "Введите размер массива: ";
	cin >> size;

	Matrix<int> matrix(size);

	cout << "Выберите способ заполнения массива:\n";
	cout << "1 - Случайными числами\n";
	cout << "2 - Вводом с клавиатуры\n";

	int choice;
	cin >> choice;

	Generator* generator = nullptr;

	switch (static_cast<FillMethod>(choice)) {
	case FillMethod::RANDOM:
		generator = new RandomGenerator();
		cout << "Массив будет заполнен случайными числами от -1000 до 1000" << endl;
		break;

	case FillMethod::MANUAL:
		generator = new IStreamGenerator(cin);
		cout << "Введите элементы массива:" << endl;
		break;

	default:
		cout << "Неверный выбор. Будет использован случайный генератор." << endl;
		generator = new RandomGenerator();
		break;
	}

	matrix.fill(*generator);
	cout << "Исходный массив: " << matrix << endl;


	ConcreteExercise1<int> exercise1(matrix, *generator);
	exercise1.task();
	cout << "Массив после выполнения 1 условия: " << exercise1.getMatrix() << endl;


	ConcreteExercise2<int> exercise2(matrix, *generator);
	exercise2.task();
	cout << "Массив после выполнения 2 условия: " << exercise2.getMatrix() << endl;


	ConcreteExercise3<int> exercise3(matrix, *generator);
	exercise3.task();
	cout << "Массив после выполнения 3 условия: " << exercise3.getMatrix() << endl;

	delete generator;

	return 0;
}
