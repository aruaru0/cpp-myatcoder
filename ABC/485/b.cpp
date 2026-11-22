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

    rep(i, n)
    {
        int cnt = 0;
        rep(j, m) if (s[i][j] == 'x') cnt++;
        if (cnt == m)
        {
            cout << "Faucet " << i + 1 << endl;
        }
    }

    rep(j, m)
    {
        int cnt = 0;
        rep(i, n) if (s[i][j] == 'x') cnt++;
        if (cnt == n)
        {
            cout << "Drain " << j + 1 << endl;
        }
    }

    return 0;
}
