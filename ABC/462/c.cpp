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
    vector<P> p(n);
    rep(i, n)
    {
        cin >> p[i].first >> p[i].second;
    }
    sort(p.begin(), p.end());

    int min_y = 1e6;
    int cnt = 0;
    for (auto [x, y] : p)
    {
        if (y < min_y)
        {
            cnt++;
        }
        min_y = min(min_y, y);
    }

    cout << cnt << endl;

    return 0;
}
