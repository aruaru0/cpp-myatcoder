#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    vector<string> t(m);
    rep(i, m) cin >> t[i];

    rep(a, n - m + 1)
    {
        rep(b, n - m + 1)
        {
            bool ok = true;
            rep(i, m) rep(j, m)
            {
                if (s[a + i][b + j] != t[i][j])
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                cout << a + 1 << " " << b + 1 << endl;
                return 0;
            }
        }
    }
    return 0;
}
