#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main()
{
    int n, m;
    cin >> n >> m;
    vector f(n, vector<bool>(n));
    rep(i, m)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (u > v)
            swap(u, v);
        f[u][v] = true;
    }
    int ans = 100;
    vector<int> a(n);
    rep(i, n) a[i] = i;
    do
    {
        // cycle * 1
        vector g(n, vector<bool>(n));
        rep(i, n)
        {
            int u = a[i], v = a[(i + 1) % n];
            if (u > v)
                swap(u, v);
            g[u][v] = true;
        }
        int c0 = 0;
        rep(i, n) rep(j, n) if (f[i][j] != g[i][j]) c0++;
        if (c0 < ans)
            ans = c0;

        // cycle * 2
        for (int d = 3; d <= n - 3; d++)
        {
            vector h(n, vector<bool>(n));
            rep(i, d)
            {
                int u = a[i], v = a[(i + 1) % d];
                if (u > v)
                    swap(u, v);
                h[u][v] = true;
            }
            rep(i, n - d)
            {
                int u = a[i + d], v = a[(i + 1) % (n - d) + d];
                if (u > v)
                    swap(u, v);
                h[u][v] = true;
            }
            int c1 = 0;
            rep(i, n) rep(j, n) if (f[i][j] != h[i][j]) c1++;
            if (c1 < ans)
                ans = c1;
        }
    } while (next_permutation(a.begin(), a.end()));

    cout << ans << '\n';
}
