#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n;
    cin >> n;
    vector<string> a(n);
    rep(i, n) cin >> a[i];

    vector<string> b = a;

    rep(i, n) rep(j, n)
    {
        int ni = i, nj = j;
        int k = min({ni + 1, nj + 1, n - ni, n - nj}) % 4;
        rep(ki, k)
        {
            swap(ni, nj);
            nj = n - 1 - nj;
        }
        b[ni][nj] = a[i][j];
    }

    rep(i, n) cout << b[i] << '\n';
    return 0;
}