#include <iostream>
#include "ArrayHandler.h"
#include <locale.h>
#include <limits>


int main() {
	
	setlocale(LC_ALL, "Russian");
	int n, k;
	int randomFill;

	std::cout << "Введите размер массива: ";
	std::cin >> n;
	while (std::cin.fail()) 
	{  
		std::cout << "Ошибка! Введите число: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> n;
	}

	ArrayHandler handler(n);

	std::cout << "Заполнить случайными числами? (1 - да, 0 - нет): ";
	std::cin >> randomFill;

	while (std::cin.fail() || (randomFill != 0 && randomFill != 1)) 
	{ 
		std::cout << "Ошибка! Введите 1 или 0: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> randomFill;
	}

	handler.fillArray(randomFill);

	std::cout << "Исходный массив: ";
	handler.printArray(); 

	handler.replaceFirstMultipleOf5();
	std::cout << "После замены первого кратного 5: ";
	handler.printArray();

	std::cout << "Введите значение K для вставки: ";
	std::cin >> k;
	handler.insertAfterOddStartingWithK(k);
	std::cout << "После вставки K: ";
	handler.printArray();

	auto transformedArray = handler.transformArray();
	std::cout << "Преобразованный массив: ";
	for (int element : *transformedArray) {
		std::cout << element << " ";
	}
	std::cout << std::endl;

	return 0;
}
