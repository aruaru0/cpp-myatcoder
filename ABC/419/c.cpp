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
    vector<int> r(n), c(n);
    const int inf = 1e9 + 1;
    int min_r = inf, max_r = 0, min_c = inf, max_c = 0;
    rep(i, n)
    {
        cin >> r[i] >> c[i];
        min_r = min(min_r, r[i]);
        max_r = max(max_r, r[i]);
        min_c = min(min_c, c[i]);
        max_c = max(max_c, c[i]);
    }

    int dr = (max_r - min_r + 1) / 2;
    int dc = (max_c - min_c + 1) / 2;

    cout << max(dr, dc) << endl;

    return 0;
}
