#include <iostream>

using namespace std;
using ll = long long;

int main()
{
    ll h, w;
    cin >> h >> w;

    if (w * 10000 >= 25 * h * h)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}