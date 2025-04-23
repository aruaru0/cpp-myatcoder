#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    map<char, int> mp;
    rep(i, n)
    {
        char c;
        int v;
        cin >> c >> v;
        mp[c] = v;
    }

    int ans = 0;
    int mode = 0;
    for (auto e : s)
    {
        if (e == '+')
        {
            mode = 0;
            continue;
        }
        if (e == '-')
        {
            mode = 1;
            continue;
        }

        int val = 0;
        if (mp.find(e) != mp.end())
        {
            val = mp[e];
        }
        else
        {
            val = e - '0';
        }
        if (mode == 0)
        {
            ans += val;
        }
        else
        {
            ans -= val;
        }
    }

    cout << ans << endl;

    return 0;
}
