#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;

    ll ans = 0;
    vector<int> dist(n + 2);
    set<pair<int, int>> st;
    st.emplace(0, 0);
    st.emplace(2e9, n + 1);
    dist[0] = 2e9;
    ans += 2e9;

    auto update = [&](int i, int d)
    {
        ans -= dist[i];
        dist[i] = min(dist[i], d);
        ans += dist[i];
    };

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;

        // 追加し、itに場所を受け取り
        auto it = st.emplace(x, i).first;
        // １つ手前の場所との距離と後ろとの距離を求める
        int dprev = x - prev(it)->first;
        int dnext = next(it)->first - x;
        // 小さい方をansに加算
        dist[i] = min(dprev, dnext);
        ans += dist[i];

        // 手前と後ろのインデックスを求める
        int pi = prev(it)->second;
        int ni = next(it)->second;
        // 手前と後ろの距離を更新し、ansを補正
        update(pi, dprev);
        update(ni, dnext);

        cout << ans << '\n';
    }
    return 0;
}