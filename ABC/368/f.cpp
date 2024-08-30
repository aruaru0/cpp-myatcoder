#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<int> pfs(int n)
{
    vector<int> ret;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            ret.emplace_back(i);
            n /= i;
        }
    }
    if (n != 1)
    {
        ret.emplace_back(n);
    }
    return ret;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int ans = 0;
    rep(i, n)
    {
        ans ^= pfs(a[i]).size();
    }

    if (ans)
    {
        cout << "Anna" << endl;
    }
    else
    {
        cout << "Bruno" << endl;
    }

    return 0;
}
