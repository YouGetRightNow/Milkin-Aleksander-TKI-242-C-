#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <functional>
#include <locale.h>

int main() 
{
    setlocale(LC_ALL, "RU");
    std::string name1, name2;

    std::cout << "Введите имя первого файла: ";
    std::cin >> name1;
    std::cout << "Введите имя второго файла: ";
    std::cin >> name2;

    std::ifstream file1(name1);
    if (!file1.is_open()) 
    {
        std::cerr << "Ошибка открытия файла " << name1 << std::endl;
        return 1;
    }

    std::ifstream file2(name2);
    if (!file2.is_open()) 
    {
        std::cerr << "Ошибка открытия файла " << name2 << std::endl;
        return 1;
    }

    std::istream_iterator<int> iter1(file1), end1;
    std::istream_iterator<int> iter2(file2), end2;

    std::vector<int> result;

    std::merge(iter1, end1, iter2, end2,
        std::back_inserter(result),
        std::greater<int>());

    std::cout << "Объединенная последовательность (по убыванию):" << std::endl;
    std::copy(result.begin(), result.end(),
        std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}