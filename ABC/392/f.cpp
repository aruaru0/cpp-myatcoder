#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int op(int a, int b) { return a + b; }
int e() { return 0; }

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];

    segtree<int, op, e> t(vector<int>(n, 1));
    auto getKth = [&](int k)
    {
        auto f = [&](int x)
        { return x < k; };
        return t.max_right(0, f);
    };

    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int j = getKth(p[i]);
        ans[j] = i + 1;
        t.set(j, 0);
    }

    rep(i, n) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}