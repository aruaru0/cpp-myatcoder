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
    int n, k, m;

    cin >> n >> m >> k;
    vector<set<int>> p(n);

    rep(i, k)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        p[a].insert(b);
        // cout << a << " " << b << endl;
        if (p[a].size() == m)
        {
            cout << a + 1 << " ";
        }
    }

    cout << endl;

    return 0;
}
