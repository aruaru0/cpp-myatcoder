#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    mint ans;

    mint s = 0, s2 = 0;
    rep(i, n) s += a[i];
    rep(i, n) s2 += mint(a[i]) * a[i];

    ans += s2 * comb(n - 1, k - 1);
    ans += (s * s - s2) * comb(n - 2, k - 2);
    cout << ans.val() << endl;
    return 0;
}