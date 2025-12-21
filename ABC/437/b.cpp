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
    int h, w, n;
    cin >> h >> w >> n;
    vector a(h, vector<int>(w, 0));

    rep(i, h) rep(j, w) cin >> a[i][j];

    set<int> b;
    rep(i, n)
    {
        int x;
        cin >> x;
        b.insert(x);
    }

    int ans = 0;
    rep(r, h)
    {
        int tot = 0;
        rep(c, w)
        {
            if (b.find(a[r][c]) != b.end())
                tot++;
        }
        ans = max(ans, tot);
    }

    cout << ans << endl;
    return 0;
}
