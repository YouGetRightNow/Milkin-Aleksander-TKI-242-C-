#include <iostream>
#include <deque>
#include <locale.h>
#include <algorithm>
#include <iterator>

int main()
{
    setlocale(LC_ALL, "RU");
    std::deque<int> d;
    std::copy(std::istream_iterator<int>(std::cin),
        std::istream_iterator<int>(),
        std::back_inserter(d));

    size_t n = d.size();

    if (n % 4 != 0)
    {
        std::cerr << "Ошибка: количество элементов (" << n << ") не кратно 4" << std::endl;
        return 1;
    }

    size_t removal = n / 4;

    auto i = d.begin();

    for (size_t count = 0; count < removal; ++count)
    {
        ++i;
        i = d.erase(i);
    }

    std::copy(d.begin(), d.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}
