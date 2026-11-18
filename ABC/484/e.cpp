#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

// Coodinate Compression
// https://youtu.be/fR3W5IcBGLQ?t=8550
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
    int n;
    ll L, R;
    cin >> n >> L >> R;
    vector<ll> s(n + 1);
    rep(i, n)
    {
        ll a;
        cin >> a;
        s[i + 1] = s[i] + a;
    }

    n++;
    CC<ll> cc;
    rep(i, n) cc.add(s[i]), cc.add(s[i] - L), cc.add(s[i] - R);
    int m = cc.size();

    ll ans = 0;
    fenwick_tree<int> t(m);
    rep(i, n)
    {
        ans += t.sum(cc(s[i] - R), cc(s[i] - L) + 1);
        t.add(cc(s[i]), 1);
    }
    cout << ans << endl;
    return 0;
}