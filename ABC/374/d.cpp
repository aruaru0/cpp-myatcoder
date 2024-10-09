#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, s, t;
    cin >> n >> s >> t;

    vector<int> a(n), b(n), c(n), d(n);
    rep(i, n) cin >> a[i] >> b[i] >> c[i] >> d[i];

    double ans = 1e9;
    vector<int> p(n);
    rep(i, n) p[i] = i;

    while (1)
    {
        rep(bit, 1 << n)
        {
            double tot = 0.0;
            int sx = 0, sy = 0;
            // printf("%d\n", bit);
            for (auto idx : p)
            {
                int tx = a[idx], ty = b[idx];
                int nx = c[idx], ny = d[idx];
                if ((bit >> idx) % 2 == 1)
                {
                    swap(tx, nx);
                    swap(ty, ny);
                }
                double dist1 = sqrt((double)(tx - sx) * (tx - sx) + (double)(ty - sy) * (ty - sy));
                double dist2 = sqrt((double)(nx - tx) * (nx - tx) + (double)(ny - ty) * (ny - ty));
                tot += dist1 / s + dist2 / t;
                // printf("%d %d -> %d %d -> %d %d : %lf %lf\n", sx, sy, tx, ty, nx, ny, dist1 / s, dist2 / t);
                sx = nx, sy = ny;
            }
            // cout << "tot" << tot << endl;
            ans = min(ans, tot);
        }

        if (next_permutation(p.begin(), p.end()) == false)
        {
            break;
        }
    }

    printf("%.10lf\n", ans);
    return 0;
}
