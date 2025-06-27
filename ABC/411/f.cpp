#include <bits/stdc++.h>
using namespace std;

#define N (int)3e+5

int main()
{
    int n, m;
    int u[N], v[N];
    vector<int> p[N];
    int p_rev[N];
    set<int> e[N];

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        p_rev[i] = i;
        p[i].push_back(i);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> u[i] >> v[i];
        u[i]--;
        v[i]--;
        e[u[i]].insert(v[i]);
        e[v[i]].insert(u[i]);
    }

    int q, x;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> x;
        int vx = p_rev[u[x - 1]];
        int vy = p_rev[v[x - 1]];
        if (vx != vy)
        {
            int valx = (e[vx].size()) + (p[vx].size());
            int valy = (e[vy].size()) + (p[vy].size());
            if (valx > valy)
                swap(vx, vy);

            int sz = p[vx].size();
            for (int j = 0; j < sz; j++)
            {
                p[vy].push_back(p[vx][j]);
                p_rev[p[vx][j]] = vy;
            }
            p[vx].clear();

            set<int>::iterator itr = e[vx].begin();
            while (itr != e[vx].end())
            {
                int vz = (*itr);
                if (vz == vy)
                {
                    m--;
                    e[vy].erase(vx);
                }
                else
                {
                    if (e[vy].count(vz) == 1)
                        m--;
                    else
                    {
                        e[vy].insert(vz);
                        e[vz].insert(vy);
                    }
                    e[vz].erase(vx);
                }
                itr++;
            }
            e[vx].clear();
        }
        cout << m << endl;
    }
    return 0;
}
