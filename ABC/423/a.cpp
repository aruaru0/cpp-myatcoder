#include <iostream>

using namespace std;

int main()
{
    int x, c;
    cin >> x >> c;

    int d = x / (1000 + c);

    cout << d * 1000 << endl;
}