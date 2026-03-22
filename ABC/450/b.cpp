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

    map<P, int> mp;
    rep(i, n)
    {
        rep(j, n - i - 1)
        {
            int c;
            cin >> c;
            mp[P(i, j + i + 1)] = c;
        }
    }

    rep(a, n)
    {
        for (int b = a + 1; b < n; b++)
        {
            for (int c = b + 1; c < n; c++)
            {
                // cout << a << " " << b << " " << c << " " << mp[P(a, c)] << " " << mp[P(a, b)] << " " << mp[P(b, c)] << endl;
                if (mp[P(a, c)] > mp[P(a, b)] + mp[P(b, c)])
                {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;

    return 0;
}
