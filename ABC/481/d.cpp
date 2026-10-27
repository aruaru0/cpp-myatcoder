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
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--;
    t--;

    vector<vector<int>> node(n);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        node[a].push_back(b);
    }
    rep(i, n)
    {
        sort(node[i].begin(), node[i].end());
    }

    deque<int> q;
    q.push_back(s);
    int inf = 1e9;
    vector<int> dist(n, inf);
    dist[s] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop_front();

        for (int i = 0; i < node[cur].size(); i++)
        {
            int nxt = node[cur][i];
            int cost = i == 0 ? 0 : 1;

            if (dist[nxt] > dist[cur] + cost)
            {
                dist[nxt] = dist[cur] + cost;
                if (cost == 0)
                {
                    q.push_front(nxt);
                }
                else
                {
                    q.push_back(nxt);
                }
            }
        }
    }

    if (dist[t] == inf)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << dist[t] << endl;

    return 0;
}
