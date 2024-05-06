#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int op_min(int a, int b)
{
    return min(a, b);
}
int e_min()
{
    return INT_MAX;
}

int op_max(int a, int b)
{
    return max(a, b);
}

int e_max()
{
    return INT_MIN;
}

int main()
{
    int n, k;
    cin >> n >> k;

    segtree<int, op_min, e_min> smin(n);
    segtree<int, op_max, e_max> smax(n);

    rep(i, n)
    {
        int a;
        cin >> a;
        a--;
        smin.set(a, i);
        smax.set(a, i);
    }

    int ans = INT_MAX;
    rep(i, n - k + 1)
    {
        int x = smin.prod(i, i + k);
        int y = smax.prod(i, i + k);
        ans = min(ans, y - x);

        // cout << i << " " << i + k - 1 << " " << x << " " << y << endl;
    }
    cout << ans << endl;
}