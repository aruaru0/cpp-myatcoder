#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using mint = modint998244353;

mint dp[101][1 << 8][85];

int main()
{
    int n, l;
    cin >> n >> l;
    vector<string> S(n);
    rep(i, n) cin >> S[i];

    map<string, int> id;
    rep(i, n)
    {
        rep(j, S[i].size())
        {
            string prefix = S[i].substr(0, j + 1);
            id[prefix] = 0;
        }
    }
    id[""] = 0;
    int m = 0;
    vector<string> sufs;
    for (auto &p : id)
    {
        p.second = m++;
        sufs.push_back(p.first);
    }
    vector<int> mask(m);
    rep(i, m)
    {
        string t = sufs[i];
        rep(j, n)
        {
            if (t.ends_with(S[j]))
                mask[i] |= 1 << j;
        }
    }
    vector to(m, vector<int>(26));
    rep(j, m)
    {
        rep(c, 26)
        {
            string t = sufs[j];
            t += 'a' + c;
            while (!id.count(t))
                t.erase(t.begin());
            to[j][c] = id[t];
        }
    }

    int n2 = 1 << n;
    dp[0][0][0] = 1;
    rep(i, l) rep(s, n2) rep(j, m)
    {
        mint now = dp[i][s][j];
        if (now.val() == 0)
            continue;
        rep(c, 26)
        {
            int ni = i + 1;
            int nj = to[j][c];
            int ns = s | mask[nj];
            dp[ni][ns][nj] += now;
        }
    }

    mint ans;
    rep(j, m) ans += dp[l][n2 - 1][j];
    cout << ans.val() << endl;
    return 0;
}