#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
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
    int n, k, m;
    cin >> n >> k >> m;

    priority_queue<P> pq;

    rep(i, n)
    {
        int c, v;
        cin >> c >> v;
        pq.push(P(v, c));
    }

    vector<P> tmp;
    set<int> s;
    ll ans = 0;
    while (s.size() < m)
    {
        auto [v, c] = pq.top();
        pq.pop();
        if (s.find(c) == s.end())
        {
            s.insert(c);
            ans += v;
        }
        else
        {
            tmp.push_back(P(v, c));
        }
    }

    for (P p : tmp)
    {
        pq.push(p);
    }

    for (int i = m; i < k; i++)
    {
        auto [v, c] = pq.top();
        pq.pop();
        ans += v;
    }

    cout << ans << endl;

    return 0;
}
