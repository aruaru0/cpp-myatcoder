#include <iostream>

using namespace std;

int main()
{
    int n;

    cin >> n;

    int n1, n2;
    if (n % 2 == 1)
    {
        n1 = 1;
    }
    else
    {
        n1 = 2;
    }
    n2 = n - n1;
    n2 /= 2;

    string t;
    for (int i = 0; i < n2; i++)
        t += "-";
    for (int i = 0; i < n1; i++)
        t += "=";
    for (int i = 0; i < n2; i++)
        t += "-";

    cout << t << endl;
}