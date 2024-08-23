#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using ull = unsigned long long;

mt19937_64 rng(58);

const ull mod = (1ll << 61) - 1; // prime

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    const int MX = 200005;
    vector<ull> h(MX);
    rep(i, MX) h[i] = rng() % mod;

    vector<ull> sa(n + 1), sb(n + 1);
    rep(i, n) sa[i + 1] = (sa[i] + h[a[i]]) % mod;
    rep(i, n) sb[i + 1] = (sb[i] + h[b[i]]) % mod;

    rep(qi, q)
    {
        int la, ra, lb, rb;
        cin >> la >> ra >> lb >> rb;
        la--;
        lb--;
        if ((sa[ra] - sa[la] + mod) % mod == (sb[rb] - sb[lb] + mod) % mod)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}