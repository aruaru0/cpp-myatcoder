#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    auto b = a;
    sort(b.begin(), b.end());

    int L = 0, R = 0;
    rep(i, n)
    {
        if (a[i] != b[i])
            break;
        L++;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] != b[i])
            break;
        R++;
    }

    if (L + R + k >= n)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}