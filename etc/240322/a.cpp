#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

map<int, int> pfs(int n)
{
    map<int, int> ret;
    while (n % 2 == 0)
    {
        ret[2]++;
        n /= 2;
    }
    for (int i = 3; i * i <= n; i = i + 2)
    {
        while (n % i == 0)
        {
            ret[i]++;
            n /= i;
        }
    }
    if (n > 2)
    {
        ret[n]++;
    }
    return ret;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int p, q;

    cin >> p >> q;

    q /= gcd(p, q);

    int ans = 1;
    auto x = pfs(q);
    for (auto e : x)
    {
        ans *= e.first;
    }
    cout << ans << endl;

    return 0;
}