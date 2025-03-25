#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    rep(i, n) cin >> a[i];

    map<int, int> mp;
    rep(i, n) mp[a[i]]++;

    int maxa = -1;
    for (auto e : mp)
    {
        if (e.second == 1)
            maxa = max(maxa, e.first);
    }

    if (maxa == -1)
    {
        cout << -1 << endl;
        return 0;
    }

    rep(i, n)
    {
        if (a[i] == maxa)
        {
            cout << i + 1 << endl;
            return 0;
        }
    }

    return 0;
}
