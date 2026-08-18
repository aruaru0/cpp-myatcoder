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
    int q, v;
    cin >> q >> v;

    priority_queue<int> pq;

    rep(qi, q)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int t, w;
            cin >> t >> w;
            pq.push(w - t);
        }
        else
        {
            int t;
            cin >> t;
            if (pq.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                int w0 = pq.top();
                pq.pop();
                ll ans = min(t + w0, v);
                cout << ans << endl;
            }
        }
    }

    return 0;
}
