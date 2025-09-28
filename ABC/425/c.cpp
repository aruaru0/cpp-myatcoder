#include <iostream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    rep(i, n) a.push_back(a[i]);

    int n2 = n * 2;
    vector<ll> b(n2 + 1);
    rep(i, n2) b[i + 1] = b[i] + a[i];

    int offset = 0;
    rep(i, q)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int c;
            cin >> c;
            offset += c;
            offset %= n;
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l = (l - 1 + offset) % n2;
            r = (r - 1 + offset) % n2;
            ll cnt = b[r + 1] - b[l];
            cout << cnt << endl;
        }
    }
}