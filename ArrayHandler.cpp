#include "ArrayHandler.h"
#include <iostream>
#include <random>
#include <limits>
#include <string>

ArrayHandler::ArrayHandler(int n) : arr(std::make_unique<std::vector<int>>(n)) {}

void ArrayHandler::fillArray(bool randomFill) 
{
	if (randomFill) 
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distrib(-1000, 1000);
		for (int& element : *arr) 
        {
			element = distrib(gen);
		}
	}
	else 
	{
		std::cout << "Введите элементы массива:\n";
		for (int i = 0; i < arr->size(); ++i) 
		{
			std::cout << "Элемент " << i + 1 << ": ";
			std::cin >> (*arr)[i];
		}
	}
}

void ArrayHandler::printArray() const 
{
	for (int element : *arr) 
	{
		std::cout << element << " ";
	}
	
	std::cout << std::endl;
}

void ArrayHandler::replaceFirstMultipleOf5() 
{
	for (int& element : *arr) 
	{
		if (element % 5 == 0) 
		{
			element = 0;
			break;
		}
	}
}

void ArrayHandler::insertAfterOddStartingWithK(int k) 
{
	for (size_t i = 0; i < arr->size(); ++i) 
	{
		int n = 1;
		std::string str = std::to_string(n);
		if ((*arr)[i] % 2 != 0 && std::to_string((*arr)[i])[0] == std::to_string(k)[0]) 
		{
			arr->insert(arr->begin() + i + 1, k);
			++i;
		}
	}
}

std::unique_ptr<std::vector<int>> ArrayHandler::transformArray() 
{
	std::unique_ptr<std::vector<int>> m(std::make_unique<std::vector<int>>(arr->size()));
	(*m)[0] = 0;
	(*m)[arr->size() - 1] = 0;
	for (size_t i = 1; i < arr->size() - 1; ++i) 
	{
		(*m)[i] = -(*arr)[i] * (i + 1);
	}
	
	return m;
}
