#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> r(n);
    rep(i, n) cin >> r[i];

    int tot = 1;
    rep(i, n) tot *= 5;

    rep(i, tot)
    {
        vector<int> x(n);
        int e = i;
        int sum = 0;
        rep(j, n)
        {
            x[j] = e % 5 + 1;
            e /= 5;
            sum += x[j];
        }
        bool ok = true;
        rep(i, n)
        {
            if (x[n - 1 - i] > r[i] || x[n - 1 - i] == 0)
            {
                ok = false;
            }
        }
        if (sum % k != 0)
            ok = false;
        if (ok)
        {
            for (int i = n - 1; i >= 0; i--)
            {
                cout << x[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
