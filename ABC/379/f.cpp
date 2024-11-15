#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using P = pair<int, int>;

int op(int a, int b) { return max(a, b); }
int e() { return 0; }

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> h(n);
    rep(i, n) cin >> h[i];

    vector<vector<P>> qs(n);
    rep(i, q)
    {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        qs[r].emplace_back(l, i);
    }

    segtree<int, op, e> rmq(h);

    vector<int> ans(q);
    vector<int> st;
    for (int i = n - 1; i >= 0; i--)
    {

        for (auto [l, qi] : qs[i])
        {
            int max_h = rmq.prod(l + 1, i + 1);
            int now = lower_bound(st.begin(), st.end(), max_h, greater<int>()) - st.begin();
            ans[qi] = now;
        }
        while (st.size() && st.back() < h[i])
            st.pop_back();
        st.push_back(h[i]);
    }

    rep(i, q) cout << ans[i] << '\n';
    return 0;
}