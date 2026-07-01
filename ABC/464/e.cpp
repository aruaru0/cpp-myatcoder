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

void chmax(int &x, int &y)
{
    if (x < y)
    {
        x = y;
    }
}

int main()
{
    int h, w, q;
    cin >> h >> w >> q;

    vector<char> chs;
    vector<vector<int>> a(h, vector<int>(w, 0));

    chs.emplace_back('A');

    rep(i, q)
    {
        int r, c;
        char x;
        cin >> r >> c >> x;
        r--, c--;
        chs.emplace_back(x);
        a[r][c] = i + 1;
    }

    for (int r = h - 1; r >= 0; r--)
        for (int c = w - 1; c >= 0; c--)
        {
            if (r + 1 < h)
            {
                chmax(a[r][c], a[r + 1][c]);
            }
            if (c + 1 < w)
            {
                chmax(a[r][c], a[r][c + 1]);
            }
        }

    rep(i, h)
    {
        rep(j, w)
        {
            cout << chs[a[i][j]];
        }
        cout << endl;
    }

    return 0;
}
