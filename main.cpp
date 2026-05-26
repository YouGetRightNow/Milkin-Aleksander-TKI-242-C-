#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <locale.h>

using namespace std;

/**
 * @brief Точка входа в программу.
 * @return int 0 при успешном завершении работы программы.
 */
int main() 
{
    setlocale(LC_ALL, "RU");
    
    vector<int> V;
    
    cout << "Введите целые числа:" << endl;

    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(V));

    cout << "\nИсходный вектор V: ";
    for_each(V.begin(), V.end(), [](int value) 
    {
        cout << value << " ";
    });
    cout << "\n\n";

    map<int, int> M;

    for_each(V.begin(), V.end(), [&M](int value) 
    {
        M[value]++;
    });

    cout << "Элемент | Количество повторений" << endl;
    cout << "------------------------" << endl;

    for_each(M.begin(), M.end(), [](const pair<int, int>& p) 
    {
        cout << "   " << p.first << "    " << p.second << endl;
    });

    return 0;
}
