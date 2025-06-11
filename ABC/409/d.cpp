#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int pos1 = -1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] < s[i - 1])
        {
            pos1 = i - 1;
            break;
        }
    }

    if (pos1 == -1)
    {
        cout << s << endl;
        return;
    }

    int x = s[pos1];
    int pos2 = pos1 + 1;
    int pos3 = pos1 + 1;
    for (int i = pos2; i < n; i++)
    {
        if (s[i] <= x)
        {
            pos3 = i;
        }
        else
        {
            break;
        }
    }
    pos3++;

    // cout << pos1 << " " << pos2 << " " << pos3 << endl;
    string t;
    for (int i = 0; i < pos1; i++)
    {
        t += s[i];
    }
    // cout << t << endl;
    for (int i = pos2; i < pos3; i++)
    {
        t += s[i];
    }
    // cout << t << endl;
    t += s[pos1];
    for (int i = pos3; i < n; i++)
    {
        t += s[i];
    }

    cout << t << endl;
}

int main()
{
    int t;
    cin >> t;
    rep(i, t)
    {
        solve();
    }
    return 0;
}
