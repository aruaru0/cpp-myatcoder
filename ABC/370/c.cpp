#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string s, t;
    cin >> s >> t;

    int n = s.size();
    vector<string> ans;
    while (s != t)
    {
        string x(n, 'z');

        rep(i, n)
        {
            if (s[i] == t[i])
                continue;
            char c = s[i];
            s[i] = t[i];
            x = min(x, s);
            s[i] = c;
        }
        s = x;
        ans.emplace_back(x);
    }

    cout << ans.size() << endl;
    rep(i, ans.size())
    {
        cout << ans[i] << endl;
    }
    return 0;
}
