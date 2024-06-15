#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, q;
    cin >> n >> q;
    vector<ll> r(n), c(n);
    rep(i, n)
    {
        r[i] = i;
        c[i] = i;
    }
    int a, b;

    bool rot = false;
    rep(qi, q)
    {
        int op;
        cin >> op;
        switch (op)
        {
        case 1:
            cin >> a >> b;
            a--;
            b--;
            if (rot)
            {
                swap(c[a], c[b]);
            }
            else
            {
                swap(r[a], r[b]);
            }
            break;
        case 2:
            cin >> a >> b;
            a--;
            b--;
            if (rot)
            {
                swap(r[a], r[b]);
            }
            else
            {
                swap(c[a], c[b]);
            }
            break;
        case 3:
            rot = !rot;
            break;
        default:
            cin >> a >> b;
            a--;
            b--;
            if (rot)
            {
                swap(a, b);
            }
            cout << (ll)n * r[a] + c[b] << endl;
        }
    }
}