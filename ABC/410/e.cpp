#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N, H, M;
    cin >> N >> H >> M;

    vector<pair<int, int>> monsters(N);
    for (int i = 0; i < N; ++i)
    {
        int a, b;
        cin >> a >> b;
        monsters[i] = {a, b};
    }

    const int INF = numeric_limits<int>::min();
    vector<int> dp_prev(H + 1, INF);
    dp_prev[H] = M;

    int max_defeated = 0;

    for (int i = 0; i < N; ++i)
    {
        int a = monsters[i].first;
        int b = monsters[i].second;

        vector<int> dp_current(H + 1, INF);

        for (int h = 0; h <= H; ++h)
        {
            if (dp_prev[h] == INF)
                continue;
            int current_m = dp_prev[h];

            // 魔法を使わない攻撃
            if (h >= a)
            {
                int new_h = h - a;
                dp_current[new_h] = max(dp_current[new_h], current_m);
            }

            // 魔法を使う攻撃
            if (current_m >= b)
            {
                int new_m = current_m - b;
                dp_current[h] = max(dp_current[h], new_m);
            }
        }

        // モンスターを倒せたか確認
        bool defeated = false;
        for (int h = 0; h <= H; ++h)
        {
            if (dp_current[h] != INF)
            {
                defeated = true;
                break;
            }
        }

        if (defeated)
        {
            max_defeated = i + 1;
        }

        dp_prev = dp_current; // 次のステップに移行
    }

    cout << max_defeated << endl;

    return 0;
}