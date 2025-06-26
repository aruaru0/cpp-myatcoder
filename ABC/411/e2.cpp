#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 998244353LL;

long long mod_pow(long long a, long long e)
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
    int N;
    if (!(cin >> N))
        return 0;
    struct Ev
    {
        long long v;
        int idx;
    };
    vector<Ev> evs;
    evs.reserve(6LL * N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            long long x;
            cin >> x;
            evs.push_back({x, i});
        }
    }
    sort(evs.begin(), evs.end(), [](const Ev &a, const Ev &b)
         { return a.v < b.v; });

    /* 逆数テーブル 1..6 */
    long long inv[7];
    for (int k = 1; k <= 6; k++)
        inv[k] = mod_pow(k, MOD - 2);

    long long inv6 = inv[6];
    long long inv6N = mod_pow(inv6, N);

    vector<int> k(N, 0); // 今の k_i
    long long prod = 1;  // k_i>0 の積
    int zero_cnt = N;    // k_i==0 の個数

    long long ans = 0;
    size_t ptr = 0;
    while (ptr < evs.size())
    {
        long long val = evs[ptr].v;

        /* F(v-) */
        long long F_prev = (zero_cnt ? 0LL : prod * inv6N % MOD);

        /* 同値 val の更新を全部適用 */
        while (ptr < evs.size() && evs[ptr].v == val)
        {
            int i = evs[ptr].idx;
            int old = k[i];
            int ne = old + 1;
            if (old == 0)
            {
                --zero_cnt;
                prod = prod * ne % MOD;
            }
            else
            {
                prod = prod * ne % MOD * inv[old] % MOD;
            }
            k[i] = ne;
            ++ptr;
        }

        long long F_curr = (zero_cnt ? 0LL : prod * inv6N % MOD);
        long long diff = (F_curr - F_prev + MOD) % MOD;
        ans = (ans + val % MOD * diff) % MOD;
    }

    cout << ans << '\n';
    return 0;
}
