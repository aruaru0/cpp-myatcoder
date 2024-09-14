#include <iostream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];

    bool ok = true;
    rep(i, n)
    {
        if (p[i] != i + 1)
            ok = false;
    }
    if (ok)
    {
        cout << 0 << endl;
        return;
    }

    int maxp = -1;
    rep(i, n)
    {
        maxp = max(maxp, p[i]);
        if (maxp <= i + 1 && p[i] == i + 1)
        {
            ok = true;
            break;
        }
    }

    if (ok)
    {
        cout << 1 << endl;
        return;
    }

    if (p[0] == n && p[n - 1] == 1)
    {
        cout << 3 << endl;
    }
    else
    {
        cout << 2 << endl;
    }

    return;
}

int main()
{
    int t;
    cin >> t;
    rep(i, t) solve();
}