#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> pos(n), cnt(n);
    rep(i, n)
    {
        pos[i] = i;
        cnt[i] = 1;
    }

    int tot = 0;
    rep(qi, q)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            if (cnt[pos[x]] == 2)
                tot--;
            cnt[pos[x]]--;

            pos[x] = y;
            if (cnt[pos[x]] == 1)
                tot++;
            cnt[pos[x]]++;
        }
        else
        {
            cout << tot << endl;
        }
    }
    return 0;
}
