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
    cin >> n;

    map<P, int> d;
    rep(i, n)
    {
        int a, b;
        cin >> a >> b;
        d[{a, b}]++;
    }

    const int size = 500100;

    vector<ll> ans(size, n);
    ans[0] = 0;

    for (auto &[key, v] : d)
    {
        auto [a, b] = key;
        ans[0] += (ll)a * v;
        for (int k = b - a; k < size; k += b)
        {
            ans[k] -= (ll)b * v;
        }
    }

    rep(i, size - 1)
    {
        ans[i + 1] += ans[i];
    }

    int q;
    cin >> q;
    rep(i, q)
    {
        int x;
        cin >> x;
        cout << ans[x] << endl;
    }

    return 0;
}
