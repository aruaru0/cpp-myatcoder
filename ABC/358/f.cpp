#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    if (k < n || (k - n) % 2 == 1)
    {
        cout << "No" << endl;
        return 0;
    }

    vector<string> s(n * 2 + 1, string(m * 2 + 1, '+'));
    rep(i, n) rep(j, m) s[i * 2 + 1][j * 2 + 1] = 'o';
    rep(i, n) rep(j, m - 1) s[i * 2 + 1][j * 2 + 2] = '|';
    rep(i, n - 1) rep(j, m) s[i * 2 + 2][j * 2 + 1] = '-';
    s[0][m * 2 - 1] = 'S';
    s[n * 2][m * 2 - 1] = 'G';
    rep(i, n - 1) s[i * 2 + 2][m * 2 - 1] = '.';

    k -= n;
    for (int i = 0; i < n - 1; i += 2)
    {
        for (int j = m - 1; j >= 1; j--)
        {
            if (k > 0)
            {
                s[i * 2 + 2][j * 2 + 1] = '-';
                s[i * 2 + 2][j * 2 - 1] = '.';
                s[i * 2 + 1][j * 2] = '.';
                s[i * 2 + 3][j * 2] = '.';
                k -= 2;
            }
        }
    }
    if (n % 2 == 1)
    {
        for (int j = 0; j < m - 2; j += 2)
        {
            if (k > 0)
            {
                s[n * 2 - 3][j * 2 + 2] = '|';
                s[n * 2 - 1][j * 2 + 2] = '.';
                s[n * 2 - 2][j * 2 + 1] = '.';
                s[n * 2 - 2][j * 2 + 3] = '.';
                k -= 2;
            }
        }
    }

    cout << "Yes" << endl;
    rep(i, s.size()) cout << s[i] << endl;
    return 0;
}