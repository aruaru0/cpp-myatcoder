#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N))
        return 0;
    vector<int64> X(N), Y(N);
    for (int i = 0; i < N; ++i)
        cin >> X[i] >> Y[i];

    const int M = (N + 1) / 2; // 必要な最小点数

    // ---------- ランダム生成 ----------
    std::mt19937_64 rng(
        chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(0, N - 1);

    auto try_pair = [&](int i, int j) -> bool
    {
        int64 a = Y[i] - Y[j];
        int64 b = X[j] - X[i];
        int64 c = -(a * X[i] + b * Y[i]); // (a,b,c) は必ず整数

        int cnt = 0;
        for (int k = 0; k < N; ++k)
        {
            if (a * X[k] + b * Y[k] + c == 0)
            {
                ++cnt;
                if (cnt >= M)
                    break; // 早期停止
            }
        }
        if (cnt >= M)
        {
            cout << "Yes\n";
            cout << a << ' ' << b << ' ' << c << '\n';
            return true;
        }
        return false;
    };

    const int TRIALS = 80; // (3/4)^80 < 1e-9
    for (int t = 0; t < TRIALS; ++t)
    {
        int i = dist(rng);
        int j = dist(rng);
        if (i == j)
        {
            --t;
            continue;
        } // 同じインデックスは除外
        if (try_pair(i, j))
            return 0;
    }

    cout << "No\n";
    return 0;
}
