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

mint f(vector<int> a)
{
    int n = a.size();
    int l = 0, r = 0;
    rep(i, n) r += a[i];
    mint res;
    rep(i, n)
    {
        if (a[i] == 0)
            l++;
        else
            r--;
        if (a[i] == 1)
        {
            res += comb(l + r, l - 1);
        }
    }
    return res;
}

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    mint ans = 0;
    rep(x, 9)
    {
        char a = '0' + x, b = a + 1;
        vector<int> d;
        rep(i, n)
        {
            if (s[i] == a)
                d.push_back(0);
            if (s[i] == b)
                d.push_back(1);
        }
        ans += f(d);
    }
    cout << ans.val() << endl;
    return 0;
}