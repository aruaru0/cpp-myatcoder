#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
using Board = vector<string>;

int main()
{
    int n, h, w;

    cin >> n >> h >> w;
    vector<P> ab(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ab[i].first >> ab[i].second;
    }

    auto dfs = [&](auto dfs, Board s, vector<int> used) -> bool
    {
        int si = -1, sj = -1;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (s[i][j] == '.' && si == -1)
                {
                    si = i, sj = j;
                }
            }
        }
        if (si == -1)
        {
            cout << "Yes" << endl;
            return true;
        }

        for (int ri = 0; ri < n; ri++)
        {
            if (!used[ri])
            {
                auto [a, b] = ab[ri];
                for (int bi = 0; bi < 2; bi++)
                {
                    swap(a, b);
                    if (si + a > h || sj + b > w)
                        continue;
                    bool ok = true;
                    Board ns = s;
                    for (int i = 0; i < a; i++)
                    {
                        for (int j = 0; j < b; j++)
                        {
                            if (ns[si + i][sj + j] != '.')
                            {
                                ok = false;
                            }
                            ns[si + i][sj + j] = '1' + ri;
                        }
                    }
                    if (!ok)
                        continue;
                    used[ri] = 1;
                    if (dfs(dfs, ns, used))
                        return true;
                    used[ri] = 0;
                }
            }
        }
        return false;
    };

    if (!dfs(dfs, Board(h, string(w, '.')), vector<int>(n)))
    {
        cout << "No" << endl;
    }
}