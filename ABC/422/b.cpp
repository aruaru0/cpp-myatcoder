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

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    rep(r, h) rep(c, w)
    {
        if (s[r][c] == '.')
            continue;

        int cnt = 0;
        rep(i, 4)
        {
            int nr = r + dy[i];
            int nc = c + dx[i];
            if (nr < 0 || nr >= h || nc < 0 || nc >= w)
                continue;
            if (s[nr][nc] == '#')
                cnt++;
        }
        if (cnt != 2 && cnt != 4)
        {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}
