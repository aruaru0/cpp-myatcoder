#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int q;
    string s, t;
    cin >> q >> s >> t;
    int n = s.size(), m = t.size();

    vector<int> o(n);
    rep(i, n)
    {
        if (s.substr(i, m) == t)
            o[i] = 1;
    }

    vector<int> sum(n + 1);
    rep(i, n) sum[i + 1] = sum[i] + o[i];

    rep(qi, q)
    {
        int l, r;
        cin >> l >> r;
        --l;
        r -= m - 1;
        if (l < r && (sum[r] - sum[l]) >= 1)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}