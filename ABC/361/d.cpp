#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;
    n += 2;

    string s, t;
    cin >> s >> t;
    s += "..";
    t += "..";

    map<string, int> dist;
    queue<string> q;
    dist[s] = 0;
    q.push(s);

    while (!q.empty())
    {
        string cur = q.front();
        q.pop();
        int pos = 0;
        while (cur[pos] != '.')
            pos++;
        rep(i, n - 1)
        {
            if (cur[i] == '.' || cur[i + 1] == '.')
                continue;
            string nxt = cur;
            swap(nxt[i], nxt[pos]);
            swap(nxt[i + 1], nxt[pos + 1]);
            // cout << pos << " " << i << " " << cur << " " << nxt << endl;
            if (dist.count(nxt))
                continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }

    if (dist.count(t))
    {
        cout << dist[t] << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}