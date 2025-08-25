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

    vector<int> cnt(n);
    rep(j, m)
    {
        int x = 0, y = 0;
        rep(i, n)
        {
            if (s[i][j] == '0')
                x++;
            else
                y++;
        }
        if (x == 0 || y == 0)
        {

            rep(i, n) cnt[i]++;
        }
        else if (x < y)
        {
            rep(i, n) if (s[i][j] == '0') cnt[i]++;
        }
        else
        {
            rep(i, n) if (s[i][j] == '1') cnt[i]++;
        }
    }
    int mx = 0;
    rep(i, n) mx = max(mx, cnt[i]);

    rep(i, n) if (cnt[i] == mx) cout << i + 1 << " ";
    cout << endl;
    return 0;
}
