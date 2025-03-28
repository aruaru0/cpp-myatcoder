#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    string s;
    cin >> s;
    int n = s.size();

    string t = s;
    reverse(t.begin(), t.end());
    t += s;
    vector<int> z = z_algorithm(t);

    rep(i, n)
    {
        if (z[n + i] == n - i)
        {
            string ans = s;
            ans += t.substr(n - i, i);
            cout << ans << endl;
            return 0;
        }
    }
    return 0;
}