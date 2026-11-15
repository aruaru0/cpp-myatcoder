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

struct Person
{
    int s, t, id;
};

int main()
{
    int n;
    cin >> n;
    vector<Person> p(n);

    rep(i, n) cin >> p[i].s;
    rep(i, n) cin >> p[i].t;

    sort(p.begin(), p.end(), [](Person a, Person b)
         { return a.s < b.s; });

    rep(i, n) p[i].id = i + 1;

    vector<int> t(n);
    rep(i, n) t[i] = p[i].t;

    sort(t.begin(), t.end());

    ll ans = 0;
    rep(i, n)
    {
        auto [sval, tval, x] = p[i];

        ll cntA = sval - x + 1;
        int k = lower_bound(t.begin(), t.end(), tval) - t.begin();
        ll cntB = tval - k;

        ans += abs(cntA - cntB);
    }

    sort(p.begin(), p.end(), [](Person a, Person b)
         { return a.t < b.t; });

    fenwick_tree<int> bit(n + 2);
    rep(i, n)
    {
        int v = p[i].id;
        ans += bit.sum(v + 1, n + 1);
        bit.add(v, 1);
    }

    cout << ans << endl;

    return 0;
}
