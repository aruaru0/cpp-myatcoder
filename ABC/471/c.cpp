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

    set<ll> s;
    rep(i, n)
    {
        ll a;
        cin >> a;
        s.insert(a);
    }
    const ll inf = 1e18;
    s.insert(inf);
    s.insert(-inf);

    ll ans = 0;
    ll cur = 0;
    rep(i, n)
    {
        auto r = s.lower_bound(cur - 1);
        auto l = r;
        l--;
        if (abs(cur - *l) <= abs(cur - *r))
        {
            ans += abs(cur - *l);
            cur = *l;
            s.erase(*l);
        }
        else
        {
            ans += abs(cur - *r);
            cur = *r;
            s.erase(*r);
        }
    }

    cout << ans << endl;

    return 0;
}
