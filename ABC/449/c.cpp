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
    int n, L, R;
    cin >> n >> L >> R;
    string s;
    cin >> s;

    ll ans = 0;
    vector<vector<int>> p(26);
    rep(i, n)
    {
        int d = s[i] - 'a';
        p[d].push_back(i);
        int l = lower_bound(p[d].begin(), p[d].end(), i - R) - p[d].begin();
        int r = upper_bound(p[d].begin(), p[d].end(), i - L) - p[d].begin();
        ans += r - l;
    }

    cout << ans << endl;

    return 0;
}
