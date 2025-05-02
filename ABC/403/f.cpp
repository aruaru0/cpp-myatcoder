#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n;
    cin >> n;

    vector<string> dp_expr(n + 1);
    vector<string> dp_term(n + 1);
    vector<string> dp_factor(n + 1);
    auto chmin = [&](string &s, const string &t)
    {
        if (t == "")
            return;
        if (s == "" || t.size() < s.size())
            s = t;
    };

    for (int i = 1; i <= n; i = i * 10 + 1)
        dp_factor[i] = to_string(i);

    for (int i = 1; i <= n; i++)
    {
        rep(k, 2)
        {
            chmin(dp_expr[i], dp_term[i]);
            for (int j = 1; j < i; j++)
            {
                if (dp_expr[j] == "")
                    continue;
                if (dp_term[i - j] == "")
                    continue;
                chmin(dp_expr[i], dp_expr[j] + "+" + dp_term[i - j]);
            }
            chmin(dp_term[i], dp_factor[i]);
            for (int j = 1; j <= i; j++)
            {
                if (i % j)
                    continue;
                if (dp_term[j] == "")
                    continue;
                if (dp_factor[i / j] == "")
                    continue;
                chmin(dp_term[i], dp_term[j] + "*" + dp_factor[i / j]);
            }
            if (dp_expr[i] != "")
                chmin(dp_factor[i], "(" + dp_expr[i] + ")");
        }
    }

    cout << dp_expr[n] << endl;
    return 0;
}