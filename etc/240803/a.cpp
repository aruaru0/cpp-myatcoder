#include <bits/stdc++.h>
#define int long long
#define matrix vector<vector<int>>
using namespace std;
const int N = 49;
const int MOD = 998244353;

matrix mul(matrix A, matrix B)
{
    matrix C(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (A[j][i] != 0)
            {
                for (int k = 0; k < N; k++)
                {
                    C[j][k] = (C[j][k] + A[j][i] * B[i][k]) % MOD;
                }
            }
        }
    }
    return C;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    matrix initMatrix(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        initMatrix[i] = vector<int>(N);
    }

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            int x = 52;
            if (i != 6)
            {
                initMatrix[i * 7 + j][i * 7 + j + 7]++;
                x--;
            }
            if (j != 6)
            {
                initMatrix[i * 7 + j][i * 7 + j + 1]++;
                x--;
            }
            initMatrix[i * 7 + j][i * 7 + j] += x;
        }
    }

    vector<matrix> pw(31);
    pw[0] = initMatrix;
    for (int i = 1; i < 31; i++)
    {
        pw[i] = mul(pw[i - 1], pw[i - 1]);
    }

    int t;
    cin >> t;

    while (t > 0)
    {
        t--;
        int n;
        cin >> n;

        matrix v(N, vector<int>(N));
        for (int i = 0; i < N; i++)
        {
            v[i] = vector<int>(N);
        }
        v[0][0] = 1;

        for (int b = 30; b >= 0; b--)
        {
            if ((n >> b) & 1)
            {
                v = mul(v, pw[b]);
            }
        }

        cout << v[0][48] << '\n';
    }

    return 0;
}
