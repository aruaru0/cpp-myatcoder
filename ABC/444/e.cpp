#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    set<int> s;
    s.insert(-d);
    s.insert(1001001001 + d);

    long long ans = 0;
    int l = 0;
    rep(r, n)
    {
        while (1)
        {
            auto it = s.lower_bound(a[r]);
            if (*it - a[r] >= d && a[r] - *prev(it) >= d)
                break;
            s.erase(a[l]);
            l++;
        }
        s.insert(a[r]);
        ans += r - l + 1;
    }
    cout << ans << endl;
    return 0;
}