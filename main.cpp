#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <locale.h>

using namespace std;

struct less_abs : public binary_function<int, int, bool> 
{
    bool operator()(int a, int b) const 
    {
        return abs(a) < abs(b);
    }
};

int main() 
{
    setlocale(LC_ALL, "RU");
    vector<int> V;
    int n;

    cout << "¬ведите количество элементов вектора: ";
    cin >> n;

    cout << "¬ведите " << n << " целых чисел: ";
    for (int i = 0; i < n; i++) 
    {
        int x;
        cin >> x;
        V.push_back(x);
    }

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