#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// coutにvector<int>を表示させる
template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    os << "[";
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << v[i] << (i + 1 == (int)v.size() ? "" : ", ");
    }
    os << "]";
    return os;
}

int main()
{
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> r(n);

    map<int, int> mp;
    rep(i, n)
    {
        cin >> x[i] >> r[i];
        mp[x[i] + r[i]] = 1;
        mp[x[i] - r[i]] = 1;
    }

    int idx = 0;
    for (auto [k, v] : mp)
    {
        mp[k] = idx;
        idx++;
    }

    mf_graph<int> g(n + mp.size() + 2);
    int start = n + mp.size();
    int end = start + 1;
    int offset = n;

    rep(i, n)
    {
        int idxL = mp[x[i] - r[i]];
        int idxR = mp[x[i] + r[i]];
        g.add_edge(start, i, 1);
        g.add_edge(i, idxL + offset, 1);
        g.add_edge(i, idxR + offset, 1);
    }

    rep(i, mp.size()) g.add_edge(i + offset, end, 1);

    cout << g.flow(start, end) << endl;

    return 0;
}