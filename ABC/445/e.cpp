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

const int maxN = 10000000;
vector<int> spf(maxN + 1);

void init()
{
    for (int i = 1; i <= maxN; i++)
    {
        spf[i] = i;
    }

    for (int i = 2; i * i <= maxN; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= maxN; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
}

map<int, int> pfsMap(int n)
{
    map<int, int> res;
    while (n != 1)
    {
        res[spf[n]]++;
        n /= spf[n];
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    vector<map<int, int>> a(n);
    map<int, int> x1, x2;
    rep(i, n)
    {
        int x;
        cin >> x;

        a[i] = pfsMap(x);
        for (auto [e, cnt] : a[i])
        {
            if (x1[e] < cnt)
            {
                x2[e] = x1[e];
                x1[e] = cnt;
            }
            else if (x2[e] < cnt)
            {
                x2[e] = cnt;
            }
        }
    }

    mint tot = 1;
    for (auto [e, cnt] : x1)
    {
        tot *= ((mint)e).pow(cnt);
    }

    rep(i, n)
    {
        mint sum = tot;
        for (auto [e, cnt] : a[i])
        {
            if (x1[e] != x2[e] && x1[e] == cnt)
            {
                sum /= ((mint)e).pow(cnt - x2[e]);
            }
        }
        cout << sum.val() << " ";
    }

    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    init();
    rep(i, t) solve();
    return 0;
}
