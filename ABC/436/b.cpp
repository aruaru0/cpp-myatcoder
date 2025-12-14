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
    vector<vector<int>> a(n, vector<int>(n, 0));

    int idx = 1;
    int r = 0, c = (n - 1) / 2;
    a[r][c] = idx++;
    rep(i, n * n - 1)
    {
        int nr = (r - 1 + n) % n;
        int nc = (c + 1) % n;
        if (a[nr][nc] != 0)
        {
            nr = (r + 1) % n;
            nc = c;
        }
        a[nr][nc] = idx++;
        r = nr;
        c = nc;
    }

    rep(i, n)
    {
        rep(j, n)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
