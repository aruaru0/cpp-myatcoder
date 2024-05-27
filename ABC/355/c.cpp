#include <bits/stdc++.h>

using namespace std;
using PP = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (n); i++)

PP calc(int e, int n)
{
    e--;
    int h = e / n;
    int w = e % n;
    return PP{h, w};
}

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> a(t);
    rep(i, t) cin >> a[i];

    vector<int> h(n, 0), w(n, 0);
    int x0 = 0, x1 = 0;

    rep(i, t)
    {
        auto p = calc(a[i], n);
        h[p.first]++;
        w[p.second]++;
        if (h[p.first] == n)
        {
            cout << i + 1 << endl;
            return 0;
        }
        if (w[p.second] == n)
        {
            cout << i + 1 << endl;
            return 0;
        }
        if (p.first == p.second)
        {
            x0++;
            if (x0 == n)
            {
                cout << i + 1 << endl;
                return 0;
            }
        }
        if (p.first == n - 1 - p.second)
        {
            x1++;
            if (x1 == n)
            {
                cout << i + 1 << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}
