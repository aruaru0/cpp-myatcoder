#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    bool all_same = true;
    int pls_cnt = 0;
    int minus_cnt = 0;
    rep(i, n)
    {
        if (abs(a[i]) != abs(a[0]))
            all_same = false;
        if (a[i] > 0)
            pls_cnt++;
        else
            minus_cnt++;
    }

    if (all_same == true)
    {
        if (pls_cnt == 0 || minus_cnt == 0)
        {
            cout << "Yes" << endl;
            return;
        }
        if (abs(pls_cnt - minus_cnt) <= 1)
        {
            cout << "Yes" << endl;
            return;
        }
        cout << "No" << endl;
        return;
    }

    // 絶対値で小さい順にソート
    sort(a.begin(), a.end(), [](int a, int b)
         { return abs(a) < abs(b); });

    ll x = a[0];
    ll y = a[1];
    rep(i, n - 1)
    {
        if ((ll)a[i] * y != (ll)a[i + 1] * x)
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    return;
}

int main()
{
    int t;
    cin >> t;
    rep(i, t)
    {
        solve();
    }
    return 0;
}
