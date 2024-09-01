#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int diff = abs(a - b);

    if (a == b)
        cout << 1 << endl;
    else if (diff % 2 == 1)
        cout << 2 << endl;
    else
        cout << 3 << endl;
}