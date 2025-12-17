#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
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
    int N;
    cin >> N;

    vector<int> p(N);
    rep(i, N)
    {
        cin >> p[i];
        p[i]--;
    }

    dsu uf(N);
    rep(i, N)
    {
        uf.merge(i, p[i]);
    }

    ll ans = 0;
    for (auto g : uf.groups())
    {
        if (g.size() > 1)
        {
            ans += (ll)g.size() * (g.size() - 1) / 2;
        }
    }

    cout << ans << endl;

    return 0;
}
