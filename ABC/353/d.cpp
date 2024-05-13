#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using mint = modint998244353;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    mint sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    mint ans = 0;
    for (int i = n - 1; i > 0; i--)
    {
        sum -= a[i];
        mint tot = sum;
        int x = a[i];
        while (x > 0)
        {
            x /= 10;
            tot *= 10;
        }
        ans += tot + (mint)a[i] * i;
    }
    cout << ans.val() << endl;
}