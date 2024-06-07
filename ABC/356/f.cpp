#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

template <typename T = int>
struct CC
{
    bool initialized;
    vector<T> xs;
    CC() : initialized(false) {}
    void add(T x) { xs.push_back(x); }
    void init()
    {
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        initialized = true;
    }
    int operator()(T x)
    {
        if (!initialized)
            init();
        return upper_bound(xs.begin(), xs.end(), x) - xs.begin() - 1;
    }
    T operator[](int i)
    {
        if (!initialized)
            init();
        return xs[i];
    }
    int size()
    {
        if (!initialized)
            init();
        return xs.size();
    }
};

int main()
{
    int q;
    ll k;
    cin >> q >> k;
    vector<pair<int, ll>> qs;
    CC<ll> cc;
    rep(qi, q)
    {
        int type;
        ll x;
        cin >> type >> x;
        qs.emplace_back(type, x);
        cc.add(x);
    }

    const ll INF = 3e18;
    cc.add(-INF);
    cc.add(INF);

    set<ll> s;
    s.insert(-INF);
    s.insert(INF);
    set<ll> gap;
    gap.insert(-INF);
    gap.insert(INF);
    fenwick_tree<int> d(cc.size());

    for (auto [type, x] : qs)
    {
        if (type == 1)
        {
            if (s.count(x))
            {
                auto it = s.find(x);
                s.erase(it--);
                gap.erase(x);
                ll l = *it;
                it++;
                ll r = *it;
                if (r - l > k)
                    gap.insert(l);
                d.add(cc(x), -1);
            }
            else
            {
                auto it = s.lower_bound(x);
                ll r = *it;
                it--;
                ll l = *it;
                gap.erase(l);
                s.insert(x);
                if (x - l > k)
                    gap.insert(l);
                if (r - x > k)
                    gap.insert(x);
                d.add(cc(x), 1);
            }
        }
        else
        {
            auto it = gap.lower_bound(x);
            ll r = *it;
            it--;
            ll l = *it;
            int ans = d.sum(cc(l) + 1, cc(r) + 1);
            cout << ans << '\n';
        }
    }
    return 0;
}