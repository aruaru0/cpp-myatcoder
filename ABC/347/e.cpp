#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, q;
    cin >> n >> q;

    vector<ll> cnt(n);
    set<int> st;
    ll s = 0;
    for (int qi = 0; qi < q; qi++)
    {
        int x;
        cin >> x;
        x--;
        if (st.count(x))
        {
            cnt[x] += s;
            st.erase(x);
        }
        else
        {
            cnt[x] -= s;
            st.insert(x);
        }
        s += st.size();
    }

    for (auto e : st)
    {
        cnt[e] += s;
    }

    rep(i, n)
    {
        cout << cnt[i] << ' ';
    }
    cout << endl;

    return 0;
}