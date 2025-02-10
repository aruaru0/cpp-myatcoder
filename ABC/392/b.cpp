#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, m;
    cin >> n >> m;

    set<int> a;
    rep(i, m)
    {
        int x;
        cin >> x;
        a.insert(x);
    }

    cout << n - a.size() << endl;
    for (int i = 1; i <= n; i++)
    {
        if (a.find(i) == a.end())
        {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
