#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, ll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int H, W, M;
    cin >> H >> W >> M;
    tuple<int, int, int> op[M];
    rep(i, M)
    {
        int t, a, x;
        cin >> t >> a >> x;
        op[i] = make_tuple(t, a, x);
    }

    set<int> h;
    set<int> w;
    vector<ll> mp(210000);

    mp[0] = (ll)H * W;

    for (int i = M - 1; i >= 0; i--)
    {
        auto t = get<0>(op[i]);
        auto a = get<1>(op[i]);
        auto x = get<2>(op[i]);

        // cout << ">" << t << " " << a << " " << x << endl;
        if (t == 1)
        {
            if (h.find(a) == h.end())
            {
                int cnt = W - w.size();
                if (cnt != 0)
                {
                    // cout << "H -> " << x << " " << cnt << endl;
                    mp[0] -= cnt;
                    mp[x] += cnt;
                    h.insert(a);
                }
            }
        }
        else
        {
            if (w.find(a) == w.end())
            {
                int cnt = H - h.size();
                if (cnt != 0)
                {
                    // cout << "W -> " << x << " " << cnt << endl;
                    mp[0] -= cnt;
                    mp[x] += cnt;
                    w.insert(a);
                }
            }
        }
        // cout << "HW " << h.size() << " " << w.size() << endl;
    }

    vector<P> ans;
    for (int i = 0; i < 210000; i++)
    {
        if (mp[i] != 0)
        {
            ans.push_back(make_pair(i, mp[i]));
        }
    }

    cout << ans.size() << endl;
    for (auto e : ans)
    {
        cout << e.first << " " << e.second << endl;
    }

    return 0;
}
