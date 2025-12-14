#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

// Cartesian Tree
// https://youtu.be/XVu8-ZnuOiA?t=9291
template <class T = long long>
struct CartesianTree
{
    int n, root;
    vector<int> l, r;
    CartesianTree() {}
    CartesianTree(const vector<T> &a, bool _max = true)
    {
        n = a.size();
        l = r = vector<int>(n, -1);
        vector<int> st;
        rep(i, n)
        {
            int p = -1;
            while (st.size() && !((a[st.back()] < a[i]) ^ _max))
            {
                int j = st.back();
                st.pop_back();
                r[j] = p;
                p = j;
            }
            l[i] = p;
            st.push_back(i);
        }
        rep(i, st.size() - 1) r[st[i]] = st[i + 1];
        root = st[0];
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    CartesianTree t(p);

    auto f = [&](auto f, int v) -> ll
    {
        int l = t.l[v], r = t.r[v];
        ll res = 0;
        if (l != -1)
            res = max(res, f(f, l) + (v - l));
        if (r != -1)
            res = max(res, f(f, r) + (r - v));
        return res;
    };
    cout << f(f, t.root) << endl;
    return 0;
}