#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <locale.h>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");
    vector<int> V = { 5, 2, 8, 2, 5, 6, 8, 1, 9, 2, 5 };
    cout << "Исходный вектор V: ";
    for_each(V.begin(), V.end(), [](int value) 
        {
        cout << value << " ";
        });
    cout << endl << endl;

    map<int, int> M;

    for_each(V.begin(), V.end(), [&M](int value) 
        {
        M[value]++;
        });

    cout << "Элемент | Количество повторений" << endl;
    cout << "------------------------" << endl;

    for_each(M.begin(), M.end(), [](const auto& pair) 
        {
        cout << "   " << pair.first << "    " << pair.second << endl;
        });

    return 0;
}
