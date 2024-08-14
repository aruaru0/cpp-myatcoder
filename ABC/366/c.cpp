#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int q;
    cin >> q;
    map<int, int> mp;
    rep(qi, q)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x;
            cin >> x;
            mp[x]++;
        }
        else if (t == 2)
        {
            int x;
            cin >> x;
            mp[x]--;
            if (mp[x] == 0)
            {
                mp.erase(x);
            }
        }
        else
        {
            cout << mp.size() << endl;
        }
    }
    return 0;
}
