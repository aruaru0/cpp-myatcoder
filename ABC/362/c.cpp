#include <iostream>
#include <vector>

using ll = long long;
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    vector<int> a(n);
    ll tot = 0;
    rep(i, n)
    {
        cin >> l[i] >> r[i];
        a[i] = l[i];
        tot += a[i];
    }

    if (tot > 0)
    {
        cout << "No" << endl;
        return 0;
    }

    rep(i, n)
    {
        ll d = min(-tot, (ll)(r[i] - l[i]));
        a[i] += d;
        tot += d;
    }

    if (tot != 0)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
        rep(i, n)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}