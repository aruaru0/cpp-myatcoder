#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;
using ll = long long;

int getI()
{
    int x;
    cin >> x;
    return x;
}

vector<ll> getInts(ll n)
{
    vector<ll> vec(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> vec[i];
    }
    return vec;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll N = getI();
    vector<ll> A = getInts(N);
    sort(A.begin(), A.end());

    const ll M = 1000000;
    vector<ll> a(M + 1, 0);
    map<ll, ll> p;
    for (const auto &e : A)
    {
        a[e]++;
        p[e]++;
    }
    for (int i = 0; i < M; ++i)
    {
        a[i + 1] += a[i];
    }

    ll ans = 0;
    for (const auto &[v, t] : p)
    {
        ans += t * (t - 1) / 2;
        for (int i = 1; i < M / v + 1; ++i)
        {
            ll c = a[min(M, (i + 1) * v - 1)] - a[i * v - 1];
            if (i == 1)
            {
                c -= t;
            }
            ans += t * c * i;
        }
    }

    cout << ans << endl;

    return 0;
}
