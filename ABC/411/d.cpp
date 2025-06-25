#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> op(q), p(q);
    vector<string> s(q);
    for (int i = 0; i < q; i++)
    {
        cin >> op[i] >> p[i];
        if (op[i] == 2)
        {
            cin >> s[i];
            reverse(s[i].begin(), s[i].end());
        }
    }

    string ans;
    int i = 0;
    for (int t = q - 1; t >= 0; t--)
    {
        if (op[t] == 1)
        {
            if (i == p[t])
            {
                i = 0;
            }
        }
        else if (op[t] == 2)
        {
            if (i == p[t])
            {
                ans += s[t];
            }
        }
        else
        {
            if (i == 0)
            {
                i = p[t];
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}
