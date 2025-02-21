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

    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }

    vector<tuple<int, int, int>> query(q);

    rep(i, q)
    {
        int r, x;
        cin >> r >> x;
        query[i] = make_tuple(r, x, i);
    }
    sort(query.begin(), query.end());

    int inf = 1e9 + 10;
    vector<int> dp(n, inf);

    int idx = 0;
    vector<int> ans(q);

    rep(i, n)
    {
        int pos = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        dp[pos] = a[i];

        while (idx < q && get<0>(query[idx]) == i + 1)
        {
            int pos = lower_bound(dp.begin(), dp.end(), get<1>(query[idx]) + 1) - dp.begin();
            ans[get<2>(query[idx])] = pos;
            idx++;
        }
    }

    rep(i, q)
    {
        cout << ans[i] << endl;
    }

    return 0;
}
