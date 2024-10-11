#include <bits/stdc++.h>
using namespace std;
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

void chmin(ll &a, ll b) { a = min(a, b); }

int main()
{
    int n, k;
    ll x;
    cin >> n >> k >> x;
    vector<ll> t(n);
    rep(i, n) cin >> t[i];

    const ll INF = 1e18;
    CC<ll> cc;
    rep(i, n) rep(j, n + 1) cc.add(t[i] + x * j);
    cc.add(-1);
    cc.add(INF);

    int m = cc.size();
    vector dp(m, vector<ll>(n + 1, INF));
    dp[0][0] = 0;

    vector<int> order(m);
    rep(i, n) order[cc(t[i])]++;
    vector<int> orderS(m + 1);
    rep(i, m) orderS[i + 1] = orderS[i] + order[i];
    auto sum = [&](int l, int r)
    {
        return orderS[r] - orderS[l];
    };

    rep(i, m - 1)
    {
        rep(j, n + 1)
        {
            ll now = dp[i][j];
            if (now == INF)
                continue;
            {
                int nj = j + order[i + 1];
                chmin(dp[i + 1][nj], now);
            }
            {
                int ni = cc(cc[i] + x);
                int nj = j;
                int o = min(nj, k);
                nj -= o;
                nj += sum(i + 1, ni + 1);
                // cout << ni << " " << nj << endl;
                chmin(dp[ni][nj], now + cc[i] * o);
            }
            // printf("%d %d: %lld\n", i, j, now);
        }
    }

    ll ans = dp[m - 1][0];
    rep(i, n) ans -= t[i];
    cout << ans << endl;
    return 0;
}
