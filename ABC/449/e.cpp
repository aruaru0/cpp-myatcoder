#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

// Binary Indexed Tree (Fenwick Tree)
// https://youtu.be/lyHk98daDJo?t=7960
template <typename T>
struct BIT
{
    int n;
    vector<T> d;
    BIT(int n = 0) : n(n), d(n + 1) {}
    void add(int i, T x = 1)
    {
        for (i++; i <= n; i += i & -i)
        {
            d[i] += x;
        }
    }
    T sum(int i)
    {
        T x = 0;
        for (i++; i; i -= i & -i)
        {
            x += d[i];
        }
        return x;
    }
    T sum(int l, int r)
    {
        return sum(r - 1) - sum(l - 1);
    }
    int getKth(T k)
    {
        int w = 1, i = 0;
        while (w < n)
            w <<= 1;
        for (; w; w >>= 1)
        {
            if (i + w > n)
                continue;
            if (d[i + w] < k + 1)
                k -= d[i += w];
        }
        return i;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a[i], a[i]--;
    int q;
    cin >> q;
    vector<int> ans(q);
    vector<pair<ll, int>> qs;
    rep(qi, q)
    {
        ll x;
        cin >> x;
        x--;
        if (x < n)
            ans[qi] = a[x];
        else
            qs.emplace_back(x, qi);
    }
    sort(qs.rbegin(), qs.rend());

    vector<vector<int>> adds(n + 1);
    {
        vector<int> cnt(m);
        rep(i, n) cnt[a[i]]++;
        rep(i, m) adds[cnt[i]].push_back(i);
    }

    BIT<int> bit(m);
    int num = 0;
    ll l = n;
    rep(c, n + 1)
    {
        for (int i : adds[c])
            bit.add(i, 1), num++;
        while (qs.size() && qs.back().first < l + num)
        {
            auto [x, qi] = qs.back();
            qs.pop_back();
            ans[qi] = bit.getKth(x - l);
        }
        l += num;
    }
    while (qs.size())
    {
        auto [x, qi] = qs.back();
        qs.pop_back();
        ans[qi] = (x - l) % m;
    }

    rep(i, q) cout << ans[i] + 1 << '\n';
    return 0;
}