//
// https://atcoder.jp/contests/abc482/submissions/80494073　を写経
//
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> C(N);
    for (int i = 0; i < N; i++)
        cin >> C[i], C[i]--;

    auto bfs_dist = [&](int root) -> vector<int>
    {
        vector<int> dist(N, N);
        dist[root] = 0;
        queue<int> qu;
        qu.push(root);
        while (!qu.empty())
        {
            int x = qu.front();
            qu.pop();
            for (auto y : G[x])
                if (dist[y] > dist[x] + 1)
                {
                    dist[y] = dist[x] + 1;
                    qu.push(y);
                }
        }
        return dist;
    };
    auto find_furthest = [&](const vector<int> &dist)
    {
        return max_element(dist.begin(), dist.end()) - dist.begin();
    };
    auto dist0 = bfs_dist(0);
    int v1 = find_furthest(dist0);
    auto dist1 = bfs_dist(v1);
    int v2 = find_furthest(dist1);
    auto dist2 = bfs_dist(v2);

    int diam = dist1[v2];
    long long ans = 0;

    if (diam % 2 == 0)
    {
        int c = -1;
        for (int i = 0; i < N; i++)
            if (dist1[i] == diam / 2 && dist2[i] == diam / 2)
                c = i;
        vector<int> count_total(N), count_subtree(N);
        stack<int> st;
        auto dfs = [&](auto dfs, int x, int p, int dist) -> void
        {
            if (dist == diam / 2)
            {
                ans += count_total[C[x]]++;
                ans -= count_subtree[C[x]]++;
                st.push(x);
            }
            for (auto y : G[x])
            {
                if (y == p)
                    continue;
                dfs(dfs, y, x, dist + 1);
                if (x == c)
                {
                    while (!st.empty())
                    {
                        count_subtree[C[st.top()]] = 0;
                        st.pop();
                    }
                }
            }
        };
        dfs(dfs, c, -1, 0);
    }
    else
    {
        int c1 = -1, c2 = -1;
        for (int i = 0; i < N; i++)
        {
            if (dist1[i] == (diam - 1) / 2 && dist2[i] == (diam + 1) / 2)
                c1 = i;
            if (dist1[i] == (diam + 1) / 2 && dist2[i] == (diam - 1) / 2)
                c2 = i;
        }
        vector<int> count1(N), count2(N);
        auto dfs = [&](auto dfs, int x, int p, int dist, vector<int> &count) -> void
        {
            if (dist == (diam - 1) / 2)
                count[C[x]]++;
            for (auto y : G[x])
            {
                if (y == p)
                    continue;
                dfs(dfs, y, x, dist + 1, count);
            }
        };
        dfs(dfs, c1, c2, 0, count1);
        dfs(dfs, c2, c1, 0, count2);
        for (int i = 0; i < N; i++)
            ans += (long long)count1[i] * count2[i];
    }
    cout << ans << "\n";
}