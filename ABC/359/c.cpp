#include <iostream>

using namespace std;
using ll = long long;

int main()
{
    ll sx, sy, tx, ty;
    cin >> sx >> sy;
    cin >> tx >> ty;

    // 左側に寄せる
    if (sy % 2 == 0 && sx % 2 == 1)
    {
        sx--;
    }
    if (sy % 2 == 1 && sx % 2 == 0)
    {
        sx--;
    }
    if (ty % 2 == 0 && tx % 2 == 1)
    {
        tx--;
    }
    if (ty % 2 == 1 && tx % 2 == 0)
    {
        tx--;
    }

    ll dx = abs(sx - tx);
    ll dy = abs(sy - ty);

    ll ans = dy + max(0ll, dx - dy) / 2;

    cout << ans << endl;
}