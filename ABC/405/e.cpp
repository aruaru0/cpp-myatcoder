#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int MOD = 998244353;

// べき乗（繰り返し二乗法）
long long mod_pow(long long a, long long e = MOD - 2)
{
    long long r = 1;
    while (e)
    {
        if (e & 1)
            r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B, C, D; // 入力そのまま
    cin >> A >> B >> C >> D;

    const long long oranges = B; // B : オレンジ
    const long long bananas = C; // C : バナナ
    const long long grapes = D;  // D : ブドウ
    const long long N = A + oranges + bananas + grapes;

    /* 階乗 & 逆階乗 */
    vector<long long> fact(N + 1), invfact(N + 1);
    fact[0] = 1;
    for (long long i = 1; i <= N; ++i)
        fact[i] = fact[i - 1] * i % MOD;
    invfact[N] = mod_pow(fact[N]);
    for (long long i = N; i >= 1; --i)
        invfact[i - 1] = invfact[i] * i % MOD;

    auto Cnk = [&](long long n, long long r) -> long long
    {
        if (r < 0 || r > n)
            return 0;
        return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
    };

    long long ans = 0;
    for (long long k = 0; k <= oranges; ++k)
    {
        long long left = Cnk(A + k - 1, A - 1); // リンゴ+オレンジ(k)
        long long right = Cnk(bananas + grapes + oranges - k,
                              bananas); // バナナ+ブドウ+残りオレンジ
        ans = (ans + left * right) % MOD;
    }
    cout << ans << '\n';
    return 0;
}
