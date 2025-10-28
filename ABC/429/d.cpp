#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// coutにvector<int>を表示させる
template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    os << "[";
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << v[i] << (i + 1 == (int)v.size() ? "" : ", ");
    }
    os << "]";
    return os;
}

int main()
{
    ll N, M, C;
    cin >> N >> M >> C;

    map<ll, ll> mp;
    rep(i, N)
    {
        ll a;
        cin >> a;
        mp[a]++;
    }

    vector<P> b;
    for (auto [idx, num] : mp)
    {
        b.push_back(P(idx, num));
    }
    ll n = b.size();
    for (auto [idx, num] : mp)
    {
        b.push_back(P(idx + M, num));
    }

    sort(b.begin(), b.end());

    for (ll i = 1; i < b.size(); i++)
    {
        b[i].second += b[i - 1].second;
    }

    // for (auto [e, num] : b)
    // {
    //     cout << e << " " << num << endl;
    // }

    ll ans = 0;
    for (ll idx = 0; idx < n; idx++)
    {
        ll pos0 = b[idx].first;
        ll pos1 = b[idx + 1].first;
        ll diff = pos1 - pos0;

        ll ng = -1, ok = b.size();
        while (ng + 1 != ok)
        {
            ll m = (ok + ng) / 2;
            if (b[m].second - b[idx].second < C)
            {
                ng = m;
            }
            else
            {
                ok = m;
            }
        }
        ans += diff * (b[ok].second - b[idx].second);
        // cout << ok << endl;
    }

    cout << ans << endl;
    return 0;
}
