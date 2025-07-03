#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<int> prime_enumerate(int N)
{
    vector<bool> is_prime(N + 1, true);
    vector<int> primes;
    if (N < 2)
        return primes;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= N; ++i)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 2; i <= N; ++i)
    {
        if (is_prime[i])
            primes.push_back(i);
    }
    return primes;
}

int main()
{
    long long L, R;
    cin >> L >> R;
    vector<int> vis(R - L);
    int ans = 1;
    for (int p : prime_enumerate(sqrt(R) + 100))
    {
        for (long long x = (L / p + 1) * p; x <= R; x += p)
        {
            if (vis[x - (L + 1)])
                continue;
            vis[x - (L + 1)] = 1;
            long long y = x;
            while (y % p == 0)
                y /= p;
            if (y == 1)
                ans++;
        }
    }
    for (int v : vis)
        ans += v == 0;
    cout << ans << "\n";
}
