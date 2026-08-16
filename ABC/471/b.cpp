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

    map<string, int> mp;
    rep(i, n)
    {
        string s;
        cin >> s;
        string t = s;
        transform(s.begin(), s.end(), t.begin(), [](char c)
                  { return tolower(c); });
        mp[t]++;
    }

    int ans = 0;
    for (auto [k, v] : mp)
    {
        ans = max(ans, v);
    }

    cout << ans << endl;

    return 0;
}
