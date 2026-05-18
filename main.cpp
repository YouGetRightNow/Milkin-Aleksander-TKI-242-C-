#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <locale.h>
#include <iterator>

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
