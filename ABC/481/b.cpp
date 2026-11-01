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
    string s[5];

    rep(i, 5) cin >> s[i];

    int ans = 5;
    {
        rep(i, 5)
        {
            int c0 = 0, c1 = 0;
            rep(j, 5)
            {
                if (s[i][j] == '.')
                    c0++;
                if (s[j][i] == '.')
                    c1++;
            }
            ans = min(ans, min(c0, c1));
        }
    }
    {
        int c0 = 0, c1 = 0;
        rep(i, 5)
        {
            if (s[i][i] == '.')
                c0++;
            if (s[i][4 - i] == '.')
                c1++;
        }
        ans = min(ans, min(c0, c1));
    }

    cout << ans << endl;

    return 0;
}
