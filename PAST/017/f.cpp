#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;
const ll inf = 998244353;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> node(n);
    for (int i = 0; i < n - 1; i++)
    {
        int p;
        cin >> p;
        p--;
        node[p].push_back(i + 1);
    }

    vector<int> s(n);
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        if (t == "+")
        {
            s[i] = -1;
        }
        else if (t == "x")
        {
            s[i] = -2;
        }
        else
        {
            s[i] = stoi(t);
        }
    }

    const ll mod = 998244353;

    auto dfs = [&](auto dfs, int cur) -> ll
    {
        if (s[cur] > 0)
        {
            return s[cur];
        }

        ll x0 = dfs(dfs, node[cur][0]);
        ll x1 = dfs(dfs, node[cur][1]);

        ll ret = 0;
        if (s[cur] == -1)
        {
            ret = (x0 + x1) % mod;
        }
        else
        {
            ret = (x0 * x1) % mod;
        }

        return ret;
    };

    cout << dfs(dfs, 0) << endl;
}