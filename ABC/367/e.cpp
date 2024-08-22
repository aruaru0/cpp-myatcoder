#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N;
    ll K;
    cin >> N >> K;

    vector<vector<int>> x(65, vector<int>(N, 0));
    rep(i, N) x[0][i] = i;
    for (int i = 0; i < N; i++)
    {
        int p;
        cin >> p;
        x[1][i] = x[0][p - 1];
    }

    vector<int> a(N);
    rep(i, N) cin >> a[i];
    for (int i = 2; i < 65; i++)
    {
        rep(j, N)
        {
            x[i][j] = x[i - 1][x[i - 1][j]];
        }
    }

    int pos = 1;
    while (K > 0)
    {
        if (K % 2 == 1)
        {
            vector<int> tmp(N);
            rep(i, N) tmp[i] = a[x[pos][i]];
            swap(a, tmp);
        }
        pos++;
        K /= 2;
    }

    rep(i, N)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
