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
    string s;
    cin >> s;
    int n;
    n = s.size();

    int cnt = 0;
    rep(d, 2)
    {
        rep(i, n)
        {
            int l = i, r = i + d;
            int miss = 0;
            while (0 <= l && r < n)
            {
                if (s[l] != s[r])
                {
                    miss++;
                }
                if (miss > 1)
                {
                    break;
                }
                l--, r++;
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}
