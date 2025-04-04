#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

// modint998244353 を使う
using mint = modint998244353;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<mint> A(N);
    for (int i = 0; i < N; i++)
    {
        long long tmp;
        cin >> tmp;
        A[i] = tmp; // mintに変換
    }

    // 1. x[i] = prefix sum of A, with x[0] = 0
    //    x[i] = A[0] + A[1] + ... + A[i-1]
    vector<mint> x(N + 1, mint(0));
    for (int i = 1; i <= N; i++)
    {
        x[i] = x[i - 1] + A[i - 1];
    }

    // 2. binomial(K, k) をあらかじめ計算 (k=0..K)
    //    Kが最大10なので直接計算でもパスカルでもOK
    vector<mint> binom(K + 1, mint(0));
    // パスカルの三角形で求める
    vector<vector<mint>> pas(K + 1, vector<mint>(K + 1, mint(0)));
    pas[0][0] = 1;
    for (int i = 1; i <= K; i++)
    {
        pas[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            pas[i][j] = pas[i - 1][j - 1] + pas[i - 1][j];
        }
    }
    for (int k = 0; k <= K; k++)
    {
        binom[k] = pas[K][k];
    }

    // 3. x[i]^k を前計算しておく: powx[i][k] = x[i]^k
    //    (i=0..N, k=0..K)
    //    K<=10なので、mintのpowを使っても良いし、ループでも良い
    vector<vector<mint>> powx(N + 1, vector<mint>(K + 1, mint(0)));
    for (int i = 0; i <= N; i++)
    {
        // x[i] をベースとして k=0..K へ
        // pow(x[i], k) を計算
        // mint は .pow() で繰り返し2乗法が呼べる
        for (int k = 0; k <= K; k++)
        {
            powx[i][k] = x[i].pow(k);
        }
    }

    // 4. T[k][i] = sum_{j=0..i} of x[j]^k の累積をとる (i=0..N)
    //    k=0..K
    vector<vector<mint>> T(K + 1, vector<mint>(N + 1, mint(0)));
    for (int k = 0; k <= K; k++)
    {
        mint acc = 0;
        for (int i = 0; i <= N; i++)
        {
            acc += powx[i][k];
            T[k][i] = acc;
        }
    }

    // 5. 主和を計算
    // sum_{r=1..N} sum_{k=0..K} [ binomial(K,k)* (-1)^k * x[r]^(K-k) * T[k][r-1] ]
    mint ans = 0;
    for (int r = 1; r <= N; r++)
    {
        for (int k = 0; k <= K; k++)
        {
            // C(K,k)
            mint c = binom[k];
            // (-1)^k
            // mint で (MOD - 1) は -1 と等価
            mint sign = (k % 2 == 0) ? mint(1) : mint(-1);
            // x[r]^(K-k)
            mint val_r = powx[r][K - k];
            // sum_{m=0..r-1} x[m]^k
            mint val_t = T[k][r - 1];

            mint addVal = c * sign * val_r * val_t;
            ans += addVal;
        }
    }

    cout << ans.val() << "\n";
    return 0;
}
