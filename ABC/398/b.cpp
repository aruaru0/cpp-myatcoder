#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    vector<int> a(7);
    rep(i, 7) cin >> a[i];

    map<int, int> mp;
    rep(i, 7) mp[a[i]]++;

    int c2 = 0, c3 = 0;

    for (auto e : mp)
    {
        // cout << e.first << ":" << e.second << endl;
        if (e.second >= 2)
            c2++;
        if (e.second >= 3)
            c3++;
    }

    if (c2 >= 2 && c3 >= 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
