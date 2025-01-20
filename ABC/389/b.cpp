#include <iostream>

using namespace std;
using ll = long long;

int main()
{
    ll x;
    cin >> x;
    ll cnt = 1, n = 1;
    while (true)
    {
        cnt++;
        if (cnt * n == x)
        {
            break;
        }
        n *= cnt;
    }
    cout << cnt << endl;
}