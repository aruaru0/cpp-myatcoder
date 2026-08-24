#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll l = 0, tot = 0;
    vector<bool> eat;

    rep(r, n)
    {
        if (r - l >= m)
        {
            if (eat[l])
            {
                tot -= a[l];
            }
            l++;
        }
        if (tot + a[r] <= k)
        {
            tot += a[r];
            eat.push_back(true);
        }
        else
        {
            eat.push_back(false);
        }
    }

    for (auto e : eat)
    {
        if (e)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
