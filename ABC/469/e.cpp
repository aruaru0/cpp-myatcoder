#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<int> sum(n + 1, 0);
    for (int i = 0; i < n; i++)
        sum[i + 1] = sum[i] + (s[i] == 'o');

    auto check = [&](double mid)
    {
        double min_f = 0.0;
        int p = 0;
        for (int r = 1; r <= n; r++)
        {
            double fr = sum[r] - mid * r;
            while (p + 1 < r && sum[p + 1] <= sum[r] - k)
            {
                p++;
                double fp = sum[p] - mid * p;
                if (fp < min_f)
                    min_f = fp;
            }
            if (sum[r] >= k && min_f <= fr + 1e-12)
                return 1;
        }
        return 0;
    };

    double l = 0.0, r = 1.0;
    for (int i = 0; i < 100; i++)
    {
        double mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }

    cout << std::setprecision(17) << l << endl;
}
