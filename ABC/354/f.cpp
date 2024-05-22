#include <bits/stdc++.h>
using namespace std;

const int inf = 1100000000;

vector<int> lis(vector<int> a)
{
    int n = a.size();
    vector<int> dp(n, inf);
    vector<int> l;
    for (int i = 0; i < n; i++)
    {
        int pos = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        dp[pos] = a[i];
        l.push_back(pos + 1);
    }
    return l;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        b[n - 1 - i] = -a[i];
    }

    auto l = lis(a);
    auto r = lis(b);

    auto m = *max_element(begin(l), end(l));

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (l[i] + r[n - i - 1] - 1 == m)
        {
            ans.push_back(i + 1);
        }
    }

    cout << ans.size() << endl;
    for (auto e : ans)
    {
        cout << e << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
}