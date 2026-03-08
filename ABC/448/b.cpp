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

    vector<int> c(m);
    rep(i, m) cin >> c[i];

    int tot = 0;
    rep(i, n)
    {
        int a, b;
        cin >> a >> b;
        a--;
        int d = min(c[a], b);
        tot += d;
        c[a] -= d;
    }

    cout << tot << endl;

    return 0;
}
