#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    if (a > b)
    {
        swap(a, b);
    }
    if (c > d)
    {
        swap(c, d);
    }

    if (a > c)
    {
        swap(a, c);
        swap(b, d);
    }

    if (a < c && c < b && d > b)
    {
        cout << 4 << endl;
        return 0;
    }

    cout << 3 << endl;

    return 0;
}
