#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <locale.h>
#include <iterator>

using namespace std;

/**
 * @brief Функциональный объект для сравнения целых чисел по их абсолютным значениям.
 * @details Возвращает true, если |a| < |b|.
 */
struct less_abs : public binary_function<int, int, bool>
{
    /**
     * @brief Оператор сравнения по модулю.
     * @param a Первое число.
     * @param b Второе число.
     * @return true, если |a| < |b|, иначе false.
     */
    bool operator()(const int a, const int b) const
    {
        return abs(a) < abs(b);
    }
};

/**
 * @brief Поиск первой соседней пары чисел, нарушающей строгое возрастание модулей.
 * @details Выполняет ввод данных, поиск целевой пары и вывод результата.
 * @return int 0 при успешном завершении.
 */
int main()
{
    setlocale(LC_ALL, "RU");
    vector<int> V;

    cout << "Введите целые числа: ";

    copy(istream_iterator<int>(cin),
         istream_iterator<int>(),
         back_inserter(V));

    auto it = adjacent_find(V.begin(), V.end(), not2(less_abs()));

    if (it != V.end())
    {
        cout << *it << " " << *(it + 1) << endl;
    }
    else
    {
        cout << "0" << endl;
    }

    return 0;
}
