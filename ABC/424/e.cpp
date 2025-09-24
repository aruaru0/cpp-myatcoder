#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

void solve()
{
    int n, k, x;
    cin >> n >> k >> x;
    using P = pair<double, int>;
    priority_queue<P> q;
    rep(i, n)
    {
        int a;
        cin >> a;
        q.emplace(a, 1);
    }

    while (k)
    {
        auto [l, c] = q.top();
        q.pop();
        if (k < c)
        {
            q.emplace(l, c - k);
            c = k;
        }

        k -= c;
        q.emplace(l / 2, c * 2);
    }

    while (1)
    {
        auto [l, c] = q.top();
        q.pop();
        x -= c;
        if (x <= 0)
        {
            printf("%.10f\n", l);
            return;
        }
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}