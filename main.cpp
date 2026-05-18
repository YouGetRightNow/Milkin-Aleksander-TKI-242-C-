#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <locale.h>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");
    
    vector<int> V;
    int n, element;
    
    cout << "Введите количество элементов вектора: ";
    cin >> n;
    
    cout << "Введите " << n << " целых чисел:" << endl;
    for (int i = 0; i < n; i++) 
    {
        cout << "Элемент " << i + 1 << ": ";
        cin >> element;
        V.push_back(element);
    }
    
    cout << "\nИсходный вектор V: ";
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
