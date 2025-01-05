#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;
using col = tuple<int, int, char>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, m;
    cin >> n >> m;

    vector<col> xyc;
    rep(i, m)
    {
        int x, y;
        char c;
        cin >> x >> y >> c;
        xyc.push_back(make_tuple(x, y, c));
    }

    sort(xyc.begin(), xyc.end());

    int min_y = 1 << 30;
    string ans = "Yes";
    for (auto [x, y, c] : xyc)
    {
        if (c == 'W')
        {
            min_y = min(min_y, y);
        }
        else
        {
            if (y >= min_y)
            {
                ans = "No";
            }
        }
    }

    cout << ans << endl;
    return 0;
}
