#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll f(vector<int> xs)
{
    int n = xs.size();
    sort(xs.begin(), xs.end());
    ll res = 0;

    rep(i, n)
    {
        res += (ll)xs[i] * (i - (n - 1 - i));
    }
    return res / 2;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> xs(2), ys(2);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        int X = x + y;
        int Y = x - y;
        xs[X % 2].push_back(X);
        ys[X % 2].push_back(Y);
    }

    ll ans = 0;
    for (int i = 0; i < 2; i++)
    {
        ans += f(xs[i]) + f(ys[i]);
    }
    cout << ans << endl;
}