#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

bool done[201][201][201];
double dp[201][201][201];

int main()
{
    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    double ave = 0;
    rep(i, n) ave += a[i];
    ave /= n;

    auto f = [&](auto f, int l, int i2, int i1) -> double
    {
        if (done[l][i2][i1])
            return dp[l][i2][i1];
        if (l == 0)
            return 0;
        if (i2 == 0 && i1 == 0)
            return 0;
        double res = 0;
        double p = 1. / (i2 * 2 + i1), q = 1. / (i2 * 2 + i1 - 1);
        if (i1)
        { // 1
            res += (p * i1) * (f(f, l, i2, i1 - 1) + 1);
        }
        if (i2 && i1)
        { // 2,1
            res += (p * i2 * 2) * (q * i1) * (f(f, l - 1, i2 - 1, i1) + (l == 1 ? 0 : 1));
        }
        if (i2)
        { // 2,2 =
            res += (p * i2 * 2) * (q * 1) * (f(f, l, i2 - 1, i1) + 1);
        }
        if (i2 >= 2)
        { // 2,2 !=
            res += (p * i2 * 2) * (q * (i2 * 2 - 2)) * (f(f, l - 1, i2 - 2, i1 + 2));
        }

        done[l][i2][i1] = true;
        return dp[l][i2][i1] = res;
    };

    double ans = f(f, l, n, 0) * ave;
    printf("%.10f\n", ans);
    return 0;
}