#include <iostream>
using namespace std;

int main()
{
    int a0 = 100, a1 = 100, a2 = 200;

    for (int i = 1; i < 20; i++)
    {
        int a = a0 + a1 + a2;
        a0 = a1;
        a1 = a2;
        a2 = a;
    }

    cout << a0 << endl;
}