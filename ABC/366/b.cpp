#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    int m = 0;
    rep(i, n)
    {
        cin >> s[i];
        m = max(m, (int)s[i].size());
    }
    vector<vector<char>> t(m, vector(n, '*'));
    rep(i, n)
    {
        rep(j, s[i].size())
        {
            t[j][i] = s[i][j];
        }
    }

    rep(i, m)
    {
        rep(j, n)
        {
            if (t[i][j] == '*')
            {
                t[i][j] = 0;
            }
            else
            {
                break;
            }
        }
        for (int j = n - 1; j >= 0; j--)
        {
            if (t[i][j] != 0)
            {
                cout << t[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}
