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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int max_a = 0;
    rep(i, n) max_a = max(max_a, a[i]);

    vector<int> pos(max_a + 1, -1);
    rep(i, n)
    {
        pos[a[i]] = i;
    }

    dsu uf(n);
    ll ans = 0;

    for (int x = max_a; x >= 1; x--)
    {
        int first = -1;
        for (int y = x; y <= max_a; y += x)
        {
            if (pos[y] != -1)
            {
                if (first == -1)
                {
                    first = pos[y];
                }
                else
                {
                    if (uf.same(first, pos[y]) == false)
                    {
                        uf.merge(first, pos[y]);
                        ans += x;
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
