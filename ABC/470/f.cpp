#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using mint = modint998244353;

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

constexpr int size = 200010;
mint frac[::size], ifrac[::size];

void initfrac()
{
    frac[0] = 1;
    for (int i = 1; i < ::size; i++)
    {
        frac[i] = frac[i - 1] * i;
    }
    ifrac[::size - 1] = 1 / frac[::size - 1];
    for (int i = ::size - 2; i >= 0; i--)
    {
        ifrac[i] = ifrac[i + 1] * (i + 1);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    dsu uf(n);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        uf.merge(a, b);
    }

    mint ans = 1;
    bool single = true;
    initfrac();
    for (auto e : uf.groups())
    {
        map<int, int> mp;
        for (auto i : e)
        {
            mp[s[i]]++;
        }
        mint cnt = frac[e.size()];
        for (auto [key, val] : mp)
        {
            cnt *= ifrac[val];
            if (mp[key] > 1)
            {
                single = false;
            }
        }
        ans *= cnt;
    }
    if (single)
    {
        ans /= 2;
    }

    cout << ans.val() << endl;
    return 0;
}
