#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int k, n;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    const int D = 18;
    auto judge = [&](int x) -> int
    {
        vector<vector<int>> to(D, vector<int>(n));
        vector<vector<int>> co(D, vector<int>(n));

        int j = 0, w = 0, sum = 0;
        rep(i, n)
        {
            while (sum < x)
            {
                sum += a[j];
                w++;
                j = (j + 1) % n;
            }
            to[0][i] = j;
            co[0][i] = w;
            sum -= a[i];
            w--;
        }

        rep(i, D - 1)
        {
            rep(j, n)
            {
                to[i + 1][j] = to[i][to[i][j]];
                co[i + 1][j] = min(co[i][j] + co[i][to[i][j]], n + 1);
            }
        }

        int res = 0;
        rep(si, n)
        {
            int v = si, cost = 0;
            rep(i, D)
            {
                if (k >> i & 1)
                {
                    cost += co[i][v];
                    v = to[i][v];
                }
            }
            if (cost > n)
                res++;
        }
        return res;
    };

    ll ac = 0, wa = 0;
    rep(i, n) wa += a[i];
    while (ac + 1 < wa)
    {
        ll wj = (ac + wa) / 2;
        if (judge(wj) == n)
            wa = wj;
        else
            ac = wj;
    }
    cout << ac << " " << judge(ac) << endl;
    return 0;
}