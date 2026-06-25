#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using mint = modint998244353;

// combination mod prime
// https://youtu.be/8uowVvQ_-Mo?t=6002
// https://youtu.be/Tgd_zLfRZOQ?t=9928
struct modinv
{
    int n;
    vector<mint> d;
    modinv() : n(2), d({0, 1}) {}
    mint operator()(int i)
    {
        while (n <= i)
            d.push_back(-d[mint::mod() % n] * (mint::mod() / n)), ++n;
        return d[i];
    }
    mint operator[](int i) const { return d[i]; }
} invs;
struct modfact
{
    int n;
    vector<mint> d;
    modfact() : n(2), d({1, 1}) {}
    mint operator()(int i)
    {
        while (n <= i)
            d.push_back(d.back() * n), ++n;
        return d[i];
    }
    mint operator[](int i) const { return d[i]; }
} facts;
struct modfactinv
{
    int n;
    vector<mint> d;
    modfactinv() : n(2), d({1, 1}) {}
    mint operator()(int i)
    {
        while (n <= i)
            d.push_back(d.back() * invs(n)), ++n;
        return d[i];
    }
    mint operator[](int i) const { return d[i]; }
} ifacts;
mint comb(int n, int k)
{
    if (n < k || k < 0)
        return 0;
    return facts(n) * ifacts(k) * ifacts(n - k);
}

int main()
{
    int n;
    cin >> n;
    int n2 = n * 2;
    vector<int> a(n2);
    rep(i, n2) cin >> a[i];
    int mx = *max_element(a.begin(), a.end());

    vector<mint> ans(n2);
    auto f = [&](int w)
    {
        vector<int> d(n2); // 0:never, 1:1/2, 2:always, 3:additional
        mint p = 1;
        rep(i, n)
        {
            int li = i * 2, ri = li + 1;
            int l = a[li], r = a[ri];
            if (l > r)
                swap(l, r), swap(li, ri);
            if (r + 1 < w)
                continue;
            if (l + 1 > w)
                return;
            p *= invs(2);
            if (r == w)
            { // l win
                d[ri] = 2;
                if (l == w - 1)
                    d[li] = 2;
            }
            else
            { // r == w-1
                if (l == w - 1)
                    d[li] = d[ri] = 1, p *= 2;
                else
                    d[ri] = 3;
            }
        }

        int base = 0;
        rep(i, n2)
        {
            if (d[i] == 1 || d[i] == 2)
                base += d[i];
        }
        base /= 2;
        int add = 0;
        rep(i, n2) if (d[i] == 3) add++;
        {
            mint now = 0;
            rep(i, add + 1)
            {
                if (base + i)
                    now += comb(add, i) * invs(base + i);
            }
            now *= p;
            rep(i, n2)
            {
                if (d[i] == 1 || d[i] == 2)
                    ans[i] += now * d[i] * invs(2);
            }
        }
        {
            mint now = 0;
            rep(i, add)
            {
                now += comb(add - 1, i) * invs(base + i + 1);
            }
            now *= p;
            rep(i, n2)
            {
                if (d[i] == 3)
                    ans[i] += now;
            }
        }
    };

    f(mx);
    f(mx + 1);

    rep(i, n2) cout << ans[i].val() << ' ';
    cout << endl;
    return 0;
}