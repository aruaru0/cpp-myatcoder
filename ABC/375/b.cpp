#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    rep(i, n)
    {
        cin >> x[i] >> y[i];
    }
    x.push_back(0);
    y.push_back(0);
    int cx = 0, cy = 0;
    double ans = 0;
    rep(i, n + 1)
    {
        double dx = x[i] - cx;
        double dy = y[i] - cy;
        ans += sqrt(dx * dx + dy * dy);
        cx = x[i];
        cy = y[i];
    }
    cout << fixed;
    cout << setprecision(20);
    cout << ans << endl;
}