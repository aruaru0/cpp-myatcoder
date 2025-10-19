#include <iostream>

using namespace std;

int main()
{
    int s, a, b, x;
    cin >> s >> a >> b >> x;

    int q = x / (a + b);
    int r = x % (a + b);

    r = min(a, r);

    int ans = s * (q * a + r);

    cout << ans << endl;
}