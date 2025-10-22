#include "Matrix.h"
#include "RandomGenerator.h"
#include "IStreamGenerator.h"
#include "ConcreteExercise.h"
#include <iostream>
#include <string>
#include <locale.h>

using namespace std;
using namespace algebra;

int main()
{
    setlocale(LC_ALL, "RU");
    size_t size;
    cout << "Введите размер массива: ";
    cin >> size;

    Matrix<int> matrix(size);

    int choice;
    cout << "Выберите способ заполнения массива:\n";
    cout << "1. Случайными числами\n";
    cout << "2. Вводом с клавиатуры\n";
    cin >> choice;

    Generator* generator;
    if (choice == 1)
    {
        generator = new RandomGenerator();
        cout << "Массив будет заполнен случайными числами от -1000 до 1000" << endl;
    }
    else
    {
        generator = new IStreamGenerator(cin);
        cout << "Введите элементы массива:" << endl;
    }

    matrix.fill(*generator);
    cout << "Исходный массив: " << matrix << endl;

    ConcreteExercise<int> exercise(matrix, *generator);
    exercise.task1();
    cout << "Массив после выполнения 1 условия: " << exercise.getMatrix() << endl;

    exercise.task2();
    cout << "Массив после выполнения 2 условия: " << exercise.getMatrix() << endl;

    exercise.task3();
    cout << "Массив после выполнения 3 условия: " << exercise.getMatrix() << endl;

    delete generator;

    return 0;
}
