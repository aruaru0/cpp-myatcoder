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
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    rep(i, n) cin >> s[i];

    map<string, int> mp;

    rep(i, n - m + 1) rep(j, n - m + 1)
    {
        string t;
        rep(r, m) rep(c, m)
        {
            t += s[r + i][c + j];
        }
        mp[t]++;
    }

    cout << mp.size() << endl;

    return 0;
}
