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
    int m, d;
    cin >> m >> d;
    string s;
    cin >> s;

    vector<int> p(m);
    for (int i = 0; i < m; i++)
    {
        if (s[i] == 'G')
        {
            int l = max(0, i - d);
            int r = min(m - 1, i + d);
            for (int j = l; j <= r; j++)
            {
                p[j]++;
            }
        }
    }

    int cnt = 0;
    rep(i, m) if (p[i] == 0) cnt++;

    cout << cnt << endl;

    return 0;
}
