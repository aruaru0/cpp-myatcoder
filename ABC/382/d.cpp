#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> ans;
    auto f = [&](auto f, vector<int> a)
    {
        if (a.size() == n)
        {
            ans.push_back(a);
            return;
        }

        int l = 1;
        if (a.size() > 0)
            l = a.back() + 10;
        a.push_back(l);
        while (a.back() + 10 * (n - a.size()) <= m)
        {
            f(f, a);
            a.back()++;
        }
    };

    f(f, vector<int>());

    cout << ans.size() << '\n';
    for (auto a : ans)
    {
        rep(i, n) cout << a[i] << ' ';
        cout << '\n';
    }
    return 0;
}