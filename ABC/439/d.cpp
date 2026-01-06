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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    map<int, int> l, r;
    rep(i, n) r[a[i]]++;

    ll ans = 0;
    rep(j, n)
    {
        int cur = a[j];
        l[cur]++;
        r[cur]--;
        if (cur % 5 != 0)
            continue;
        ll k = (ll)l[cur / 5 * 3] * l[cur / 5 * 7] + (ll)r[cur / 5 * 3] * r[cur / 5 * 7];
        ans += k;
    }

    cout << ans << endl;

    return 0;
}
