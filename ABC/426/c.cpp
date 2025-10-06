#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        a[i] = 1;

    int cur_min = 0;
    rep(qi, q)
    {
        int x, y;
        cin >> x >> y;
        int cnt = 0;
        while (cur_min <= x)
        {
            cnt += a[cur_min];
            a[cur_min] = 0;
            cur_min++;
        }
        a[y] += cnt;
        cout << cnt << endl;
    }
    return 0;
}