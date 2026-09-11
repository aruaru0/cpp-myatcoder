#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (n); ++i)
using ll = long long;

vector<int> getPrimes(int n)
{
    vector<int> res;
    vector<bool> isp(n + 1, true);
    for (int i = 2; i <= n; i++)
    {
        if (!isp[i])
            continue;
        res.push_back(i);
        for (int j = i * 2; j <= n; j += i)
            isp[j] = false;
    }
    return res;
}

struct D
{
    ll a, b; // ax+b
    void operator-=(D d)
    {
        a -= d.a;
        b -= d.b;
    }
};

ll solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    rep(i, n) cin >> a[i];

    vector<int> ps = getPrimes(n);

    vector<D> d(n + 1);
    rep(i, n) d[i] = D(1, -a[i]);

    for (int p : ps)
    {
        for (int i = p; i <= n; i += p)
        {
            d[i / p] -= d[i];
        }
    }

    ll l = 0, r = 1e18;
    rep(i, n)
    {
        auto [a, b] = d[i];
        if (a == 0)
        {
            if (b < 0)
                return -1;
        }
        if (a < 0)
        {
            if (b < 0)
                return -1;
            r = min(r, b / -a);
        }
        if (a > 0)
        {
            if (b > 0)
                continue;
            l = max(l, (-b - 1 + a) / a);
        }
    }
    if (l > r)
        return -1;
    return l - a[1];
}

int main()
{
    cout << solve() << endl;
    return 0;
}