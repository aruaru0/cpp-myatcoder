#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// coutにvector<int>を表示させる
template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    os << "[";
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << v[i] << (i + 1 == (int)v.size() ? "" : ", ");
    }
    os << "]";
    return os;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    ll totA = 0, totB = 0;
    rep(i, n)
    {
        cin >> a[i];
        totA += a[i];
    }
    rep(i, n)
    {
        cin >> b[i];
        totB += b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), [](int a, int b)
         { return a > b; });

    // cout << a << endl;
    // cout << b << endl;
    // cout << totA << " " << totB << endl;

    int cnt = 0;
    int pos = 0;
    for (auto e : b)
    {
        int v = m - e;
        while (pos < n && a[pos] < v)
        {
            pos++;
        }
        if (pos < n)
        {
            cnt++;
            pos++;
        }
    }
    ll ans = (totA + totB) - (ll)cnt * m;
    cout << ans << endl;
}

int main()
{
    int T;
    cin >> T;
    rep(i, T)
    {
        solve();
    }
    return 0;
}
