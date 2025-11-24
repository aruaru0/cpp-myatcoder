#include <iostream>

using namespace std;

int main()
{
    int x, y, z;
    cin >> x >> y >> z;

    int a = x - z * y;
    int b = z - 1;

    if (a >= 0 && a % b == 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}