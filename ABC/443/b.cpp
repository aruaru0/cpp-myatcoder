#include <iostream>

using ll = long long;
using namespace std;

int main()
{
    ll n, k;
    cin >> n >> k;

    ll x;
    x = sqrt(2 * k + n * n - n - 1);

    if ((n + x) * (x - n + 1) < 2 * k)
    {
        x++;
    }
    cout << x - n << endl;
}