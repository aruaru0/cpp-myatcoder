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

int main()
{
    int n;
    string t;

    cin >> n >> t;

    vector<ll> c(2);
    int cur = 0;
    c[cur] = 1;
    rep(i, n)
    {
        int v = t[i] - '0';
        cur ^= v ^ 1;
        c[cur]++;
    }

    ll ans = (c[0] * (c[0] - 1)) / 2 + (c[1] * (c[1] - 1)) / 2;
    cout << ans << endl;

    return 0;
}
