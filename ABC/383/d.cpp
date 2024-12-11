#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

// Sieve of Eratosthenes
// https://youtu.be/UTVg7wzMWQc?t=2774
struct Sieve
{
    int n;
    vector<int> f, primes;
    Sieve(int n = 1) : n(n), f(n + 1)
    {
        f[0] = f[1] = -1;
        for (ll i = 2; i <= n; ++i)
        {
            if (f[i])
                continue;
            primes.push_back(i);
            f[i] = i;
            for (ll j = i * i; j <= n; j += i)
            {
                if (!f[j])
                    f[j] = i;
            }
        }
    }
    bool isPrime(int x) { return f[x] == x; }
    vector<int> factorList(int x)
    {
        vector<int> res;
        while (x != 1)
        {
            res.push_back(f[x]);
            x /= f[x];
        }
        return res;
    }
    vector<pair<ll, int>> factor(ll x)
    {
        vector<pair<ll, int>> res;
        for (int p : primes)
        {
            int y = 0;
            while (x % p == 0)
                x /= p, ++y;
            if (y != 0)
                res.emplace_back(p, y);
        }
        if (x != 1)
            res.emplace_back(x, 1);
        return res;
    }
};

int main()
{
    ll n;
    cin >> n;
    Sieve sieve(1e6);
    auto primes = sieve.primes;

    int ans = 0;
    for (int p1 : primes)
    {
        for (int p2 : primes)
        {
            if (p2 >= p1)
                break;
            if ((ll)p1 * p1 * p2 * p2 > n)
                break;
            ans++;
        }
    }
    for (int p : primes)
    {
        ll x = 1;
        rep(i, 8) x *= p;
        if (x > n)
            break;
        ans++;
    }
    cout << ans << endl;
    return 0;
}