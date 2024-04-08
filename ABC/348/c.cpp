#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main()
{
    int n;
    cin >> n;

    map<int, int> m;
    rep(i, n)
    {
        int a, c;
        cin >> a >> c;
        if (m.find(c) == m.end())
        {
            m[c] = a;
        }
        else
        {
            m[c] = min(m[c], a);
        }
    }

    // for (auto e : m)
    // {
    //     cout << e.first << " " << e.second << endl;
    // }

    int ans = 0;
    for (auto e : m)
    {
        ans = max(ans, e.second);
    }
    cout << ans << endl;
}