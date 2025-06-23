#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, q;

    cin >> n >> q;
    vector<int> a(q);
    rep(i, q) cin >> a[i];

    vector<int> st(n + 2, 0);
    int cnt = 0;

    vector<int> v = {1, 0, -1, 0, 0, -1, 0, 1};

    rep(i, q)
    {
        int pos = a[i];
        int x = st[pos - 1] << 2 | st[pos] << 1 | st[pos + 1];
        cnt += v[x];
        st[pos] = 1 - st[pos];
        cout << cnt << endl;
    }

    return 0;
}
