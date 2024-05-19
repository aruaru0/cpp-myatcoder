#include <iostream>

using namespace std;
using ll = long long;
int main()
{
    int h;
    cin >> h;

    ll cnt = 0, tot = 0, x = 1;
    while (tot <= h)
    {
        tot += x;
        cnt++;
        x *= 2;
    }

    cout << cnt << endl;
}