// LUOGU_RID: 152692205
#include <bits/stdc++.h>
using namespace std;

struct rule
{
    int a, b;
} rules[90090]; // 变换规则
struct point
{
    int cur, step;
};
int m, n, ans;
queue<point> q;
bool vis[10000000];

int main()
{
    ios::sync_with_stdio(0);
    cin >> m >> n;
    for (int i = 0; i < m; ++i)
        cin >> rules[i].a >> rules[i].b;
    q.push({1, 1});
    vis[1] = 1;
    while (!q.empty())
    {
        int cur = q.front().cur, step = q.front().step;
        q.pop();
        if (cur == n)
        {
            cout << step << endl;
            return 0;
        }
        for (int i = 0; i < m; ++i)
        {
            int a = rules[i].a, b = rules[i].b, nn = cur;
            if (cur >= a)
                nn += b - a;
            if (vis[nn])
                continue;
            if (nn > n + 300)
                continue;
            vis[nn] = 1;
            q.push({nn, step + 1});
        }
    }
    cout << -1 << endl;
    return 0;
}