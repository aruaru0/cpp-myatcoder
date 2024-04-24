#include <iostream>
#include <map>
#include <iomanip>

using namespace std;
using ll = long long;

ll n, a, x, y;

map<ll, double> memo;

double f(ll n)
{
    if (n == 0)
        return 0;
    if (memo.count(n))
        return memo[n];
    double res = f(n / a) + x;
    double dice = 0;
    for (int b = 2; b <= 6; b++)
    {
        dice += f(n / b);
    }
    dice /= 5;
    dice += y * 6 / 5.;
    res = min(res, dice);
    return memo[n] = res;
}

int main()
{
    cin >> n >> a >> x >> y;

    printf("%.10f\n", f(n));
}