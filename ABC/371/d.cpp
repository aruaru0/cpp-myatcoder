#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> x(n);
    rep(i, n) cin >> x[i];
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    vector<ll> q(n + 1, 0);
    rep(i, n) q[i + 1] = q[i] + p[i];

    int Q;
    cin >> Q;
    rep(qi, Q)
    {
        int l, r;
        cin >> l >> r;
        int pl = lower_bound(x.begin(), x.end(), l) - x.begin();
        int pr = upper_bound(x.begin(), x.end(), r) - x.begin();
        // cout << pl << " " << pr << endl;
        cout << q[pr] - q[pl] << endl;
    }
}