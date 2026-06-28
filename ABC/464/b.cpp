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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    int l = 0, r = w - 1;
    int t = 0, b = h - 1;

    for (int i = 0; i < h; i++)
    {
        bool ok = true;
        rep(j, w)
        {
            if (s[i][j] == '#')
            {
                ok = false;
                break;
            }
        }
        if (!ok)
        {
            t = i;
            break;
        }
    }

    for (int i = h - 1; i >= 0; i--)
    {
        bool ok = true;
        rep(j, w)
        {
            if (s[i][j] == '#')
            {
                ok = false;
                break;
            }
        }
        if (!ok)
        {
            b = i;
            break;
        }
    }

    for (int j = 0; j < w; j++)
    {
        bool ok = true;
        rep(i, h)
        {
            if (s[i][j] == '#')
            {
                ok = false;
                break;
            }
        }
        if (!ok)
        {
            l = j;
            break;
        }
    }

    for (int j = w - 1; j >= 0; j--)
    {
        bool ok = true;
        rep(i, h)
        {
            if (s[i][j] == '#')
            {
                ok = false;
                break;
            }
        }
        if (!ok)
        {
            r = j;
            break;
        }
    }

    for (int i = t; i <= b; i++)
    {
        for (int j = l; j <= r; j++)
        {
            cout << s[i][j];
        }
        cout << endl;
    }

    return 0;
}
