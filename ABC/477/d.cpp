#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n, q;
    cin >> n >> q;

    string ans(n, 'a');
    int last = -1;
    char c = 'a';
    vector<int> t(n, -1);
    vector<bool> tile(n);

    rep(qi, q)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int i;
            cin >> i;
            --i;
            if (tile[i])
            {
                t[i] = qi;
            }
            else
            {
                if (t[i] < last)
                    ans[i] = c;
            }
            tile[i] = !tile[i];
        }
        if (type == 2)
        {
            last = qi;
            cin >> c;
        }
    }

    rep(i, n) if (!tile[i])
    {
        if (t[i] < last)
            ans[i] = c;
    }

    cout << ans << endl;
    return 0;
}