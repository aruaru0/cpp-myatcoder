#include <iostream>

using namespace std;

int main()
{
    int a = 0, b = 0;
    for (int i = 0; i < 9; i++)
    {
        int x;
        cin >> x;
        a += x;
    }
    for (int i = 0; i < 8; i++)
    {
        int x;
        cin >> x;
        b += x;
    }
    cout << a - b + 1 << endl;
}