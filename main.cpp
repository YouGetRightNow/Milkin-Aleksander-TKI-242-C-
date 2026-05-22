#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <locale.h>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");
    
    vector<int> V;
    int n;
    
    cout << "Введите количество элементов вектора: ";
    cin >> n;
    
    cout << "Введите " << n << " целых чисел:" << endl;
    
    copy_n(istream_iterator<int>(cin), n, back_inserter(V));
    
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
