#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

// N, X, U, D をグローバルまたはmain内で読み込む
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll X;
    cin >> N >> X;
    vector<ll> U(N), D(N);
    ll sum = 0;
    ll H_max_possible = 1e18; // 十分大きな値で初期化
    for (int i = 0; i < N; i++)
    {
        cin >> U[i] >> D[i];
        sum += U[i] + D[i];
        H_max_possible = min(H_max_possible, U[i] + D[i]);
    }

    // 可否判定関数: 与えられた H で条件を満たすか
    auto feasible = [&](ll H) -> bool
    {
        // 各 i で、u_i の取りうる区間は [L_i, R_i]
        // L_i = max(1, H - D[i]), R_i = min(U[i], H - 1)
        ll low = max(1LL, H - D[0]);
        ll high = min(U[0], H - 1);
        if (low > high)
            return false;
        for (int i = 1; i < N; i++)
        {
            ll L = max(1LL, H - D[i]);
            ll R = min(U[i], H - 1);
            if (L > R)
                return false;
            // 前の feasible range を拡大して、i 番目との共通部分をとる
            low = max(L, low - X);
            high = min(R, high + X);
            if (low > high)
                return false;
        }
        return true;
    };

    // 二分探索で最大の H を求める
    ll lo = 2, hi = H_max_possible;
    ll best = 2; // 最低でも 2 は feasible
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        if (feasible(mid))
        {
            best = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    ll ans = sum - best * N;
    cout << ans << "\n";
    return 0;
}
