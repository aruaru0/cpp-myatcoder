#include <iostream>

using namespace std;

int main()
{
    int n;

    cin >> n;

    int a = 1;

    for (int i = 0; i < n - 1; i++)
    {
        int x = a;
        while (x > 0)
        {
            a += x % 10;
            x /= 10;
        }
    }
    cout << a << endl;
}