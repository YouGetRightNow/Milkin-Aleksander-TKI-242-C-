#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <locale.h>
using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");
    srand(time(0));
    deque<int> D;
    int N = 16;

    cout << "Исходный дек (размер " << N << "): ";
    for (int i = 0; i < N; i++) {
        D.push_back(rand() % 100);
        cout << D[i] << " ";
    }
    cout << endl;

    int iterations = N / 4;

    deque<int>::iterator i = D.begin();
    i++;

    for (int k = 0; k < iterations; k++) 
    {
        i = D.erase(i);

        if (k < iterations - 1) 
        {
            i++;
        }
    }


    cout << "\nДек после удаления (размер " << D.size() << "): ";
    for (int val : D) 
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}