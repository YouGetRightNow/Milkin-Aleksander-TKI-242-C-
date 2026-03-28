#include <iostream>
#include <deque>
#include <locale.h>

int main() 
{
    setlocale(LC_ALL, "RU");
    std::deque<int> D;
    int value;

    while (std::cin >> value) 
    {
        D.push_back(value);
    }

    int N = D.size();

    if (N % 4 != 0) 
    {
        std::cerr << "Ошибка: количество элементов (" << N << ") не кратно 4" << std::endl;
        return 1;
    }

    int removal = N / 4;
    auto i = D.begin();

    for (int count = 0; count < removal; ++count) 
    {
        ++i;
        i = D.erase(i);
    }

    for (int x : D) 
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
