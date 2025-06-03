#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, s;
    cin >> n >> s;

    int pre = 0;
    bool ok = true;
    rep(i, n)
    {
        int t;
        cin >> t;
        if (t - pre > s)
        {
            ok = false;
        }
        pre = t;
    }
    if (ok)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
