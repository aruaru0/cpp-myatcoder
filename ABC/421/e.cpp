#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void chmax(double &x, double y) { x = max(x, y); }

int main()
{
    int n = 6;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<map<vector<int>, double>> memo(3);

    auto f = [&](auto f, int rem, vector<int> keep) -> double
    {
        if (rem == 0)
        {
            double res = 0;
            rep(i, n)
            {
                int cnt = 0;
                for (int x : keep)
                    if (x == a[i])
                        cnt++;
                chmax(res, cnt * a[i]);
            }
            return res;
        }

        rem--;
        if (memo[rem].count(keep))
            return memo[rem][keep];
        auto g = [&](auto g, int num, vector<int> dice) -> double
        {
            if (num == 0)
            {
                int m = dice.size();
                double res = 0;
                rep(s, 1 << m)
                {
                    vector<int> kp = keep;
                    rep(i, m) if (s >> i & 1) kp.push_back(dice[i]);
                    chmax(res, f(f, rem, kp));
                }
                return res;
            }
            num--;
            double res = 0;
            dice.push_back(0);
            rep(i, n)
            {
                dice.back() = a[i];
                res += g(g, num, dice);
            }
            return res / n;
        };
        double res = g(g, 5 - keep.size(), {});
        return memo[rem][keep] = res;
    };

    double ans = f(f, 3, {});
    printf("%.10f\n", ans);
    return 0;
}