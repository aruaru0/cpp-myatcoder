#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> adj1(N, vector<int>(N, 0));
    vector<vector<int>> adj2(N, vector<int>(N, 0));
    int M1, M2;
    cin >> M1;
    for (int i = 0; i < M1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj1[u][v] = 1;
        adj1[v][u] = 1;
    }
    cin >> M2;
    for (int i = 0; i < M2; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj2[u][v] = 1;
        adj2[v][u] = 1;
    }
    vector<vector<int>> A(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int v;
            cin >> v;
            A[i][j] = v;
            A[j][i] = v;
        }
    }

    // rep(i, N)
    // {
    //     rep(j, N) cout << A[i][j] << " ";
    //     cout << endl;
    // }

    ll ans = 1e18;
    vector<int> p(N);
    rep(i, N) p[i] = i;
    while (true)
    {
        ll cost = 0;
        rep(i, N)
        {
            for (int j = i + 1; j < N; j++)
            {
                if (adj1[p[i]][p[j]] != adj2[i][j])
                {
                    cost += A[i][j];
                }
            }
        }
        ans = min(ans, cost);
        // for (auto e : p)
        //     cout << e << " ";
        // cout << endl;
        if (next_permutation(p.begin(), p.end()) == false)
        {
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
