#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> g(H);
    rep(i, H)
    {
        cin >> g[i];
    }

    int n;
    cin >> n;
    string s;
    cin >> s;

    rep(hi, H) rep(wi, W) if (g[hi][wi] == s[0])
    {
        vector<vector<bool>> used(H, vector<bool>(W, false));

        auto check = [&](auto check, int idx, int h, int w)
        {
            if (idx == n - 1)
            {
                return true;
            }
            used[h][w] = true;

            for (int dh = -1; dh <= 1; dh++)
            {
                for (int dw = -1; dw <= 1; dw++)
                {
                    if (dh == 0 && dw == 0)
                        continue;
                    int nh = h + dh;
                    int nw = w + dw;
                    if (nh < 0 || nh >= H || nw < 0 || nw >= W)
                        continue;
                    if (used[nh][nw])
                        continue;
                    if (g[nh][nw] == s[idx + 1])
                    {

                        if (check(check, idx + 1, nh, nw))
                        {
                            return true;
                        }
                    }
                }
            }

            used[h][w] = false;
            return false;
        };

        bool ret = check(check, 0, hi, wi);
        if (ret)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}