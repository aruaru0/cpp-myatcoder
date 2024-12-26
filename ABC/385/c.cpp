#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n) cin >> h[i];

    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        for (int step = 1; step < n; step++)
        {
            int cnt = 0;
            for (int j = i; j < n; j += step)
            {
                if (h[i] == h[j])
                {
                    cnt++;
                }
                else
                {
                    break;
                }
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;

    return 0;
}
