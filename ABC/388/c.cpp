#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    ll cnt = 0;
    rep(i, n)
    {
        int pos = lower_bound(a.begin(), a.end(), a[i] * 2) - a.begin();

        cnt += n - pos;
    }

    cout << cnt << endl;
    return 0;
}
