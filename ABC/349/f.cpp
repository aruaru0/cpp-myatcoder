#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;

vector<ll> factor(ll M)
{
    vector<ll> res;
    for (ll i = 2; i * i <= M; i++)
    {
        if (M % i == 0)
        {
            ll e = 1;
            while (M % i == 0)
            {
                M /= i;
                e *= i;
            }
            res.push_back(e);
        }
    }
    if (M != 1)
    {
        res.push_back(M);
    }
    return res;
}

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    auto m = factor(M);
    int n = m.size();
    vector<int> c(1ll << n);

    for (auto a : A)
    {
        if (M % a == 0)
        {
            ll mask = 0;
            rep(i, n)
            {
                if (a % m[i] == 0)
                    mask |= 1 << i;
            }
            c[mask]++;
        }
    }

    mint ans = -1;
    if (M != 1)
    {
        ans = 0;
    }

    for (ll mask = 0; mask < 1 << n; mask++)
    {
        int p = -1;
        if ((n - __builtin_popcount(mask)) % 2 == 0)
        {
            p = 1;
        }
        ll x = 0;
        for (ll sub = 0; sub < 1 << n; sub++)
        {
            if ((mask & sub) == sub)
            {
                x += c[sub];
            }
        }
        mint y = 2;
        ans += p * y.pow(x);
    }

    cout << ans.val() << endl;
}