#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, n)
    {
        cin >> s[i];
    }

    int ans = m;
    rep(bits, 1 << n)
    {
        int canGet = 0;
        rep(i, n)
        {
            if ((bits >> i) % 2 == 1)
            {
                rep(j, m)
                {
                    if (s[i][j] == 'o')
                    {
                        canGet |= 1 << j;
                    }
                }
            }
        }
        if (popcount((unsigned)canGet) == m)
        {
            ans = min(ans, popcount((unsigned)bits));
        }
    }

    cout << ans << endl;
}
