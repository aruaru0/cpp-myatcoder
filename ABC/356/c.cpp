#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(m, vector<int>(n, 0));
    vector<bool> r(m);

    rep(i, m)
    {
        int c;
        cin >> c;
        rep(j, c)
        {
            int x;
            cin >> x;
            a[i][x - 1] = 1;
        }
        string s;
        cin >> s;
        if (s[0] == 'o')
        {
            r[i] = true;
        }
        else
        {
            r[i] = false;
        }
    }

    int ans = 0;
    rep(bit, 1 << n)
    {
        vector<int> x(n, 0);
        rep(i, n) if ((bit >> i) % 2) x[i] = 1;
        bool ok = true;
        rep(i, m)
        {
            int cnt = 0;
            rep(j, n) if (a[i][j] == 1 && x[j] == 1) cnt++;
            if (cnt >= k && r[i] == false)
                ok = false;
            if (cnt < k && r[i] == true)
                ok = false;
        }
        if (ok)
            ans++;
    }

    cout << ans << endl;
}