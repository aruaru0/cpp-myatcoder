#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N;
    cin >> N;
    vector<string> s(N);
    rep(i, N)
    {
        cin >> s[i];
    }

    vector<vector<int>> a(N + 1, vector<int>(N + 1, 0));
    rep(i, N)
    {
        rep(j, N)
        {
            if (s[i][j] == '#')
            {
                a[i + 1][j + 1] = 1;
            }
        }
    }

    rep(i, N + 1)
    {
        rep(j, N)
        {
            a[i][j + 1] += a[i][j];
        }
    }
    rep(i, N + 1)
    {
        rep(j, N)
        {
            a[j + 1][i] += a[j][i];
        }
    }

    // rep(i, N + 1)
    // {
    //     rep(j, N + 1)
    //     {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    auto calc = [&](int x0, int y0, int x1, int y1)
    {
        return a[x1][y1] - a[x1][y0] - a[x0][y1] + a[x0][y0];
    };

    int ans = 0;
    for (int n = 3; n <= N; n++)
    {
        rep(i, N - n + 1)
        {
            rep(j, N - n + 1)
            {
                int x0 = calc(i, j, i + n, j + 1);
                int x1 = calc(i, j, i + 1, j + n);
                int x2 = calc(i + n - 1, j, i + n, j + n);
                int y = calc(i + 1, j + 1, i + n - 1, j + n);
                if (x0 == n && x1 == n && x2 == n && y == 0)
                {
                    ans = max(ans, n - 2);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}