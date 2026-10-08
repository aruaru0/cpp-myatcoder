#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using mint = modint998244353;

int main()
{
    int n;
    cin >> n;
    vector<int> q(n);
    rep(i, n) cin >> q[i];

    vector<pair<int, int>> st;
    st.emplace_back(n + 1, 1);
    mint ans = 1;
    for (int i = 1; i < n; i++)
    {
        int len = 1;
        while (st.back().first < q[i])
        {
            len += st.back().second;
            st.pop_back();
        }
        st.emplace_back(q[i], len);
        ans *= len;
    }
    cout << ans.val() << endl;
    return 0;
}