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

    map<int, int> mp;
    rep(i, n)
    {
        int a;
        cin >> a;
        mp[a] = max(mp[a], mp[a - 1] + 1);
    }

    int ans = 0;
    for (auto e : mp)
    {
        ans = max(ans, e.second);
    }
    cout << ans << endl;

    return 0;
}
