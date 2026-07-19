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
    vector<int> a(n), b(n - 1);
    rep(i, n) cin >> a[i];
    rep(i, n - 1) cin >> b[i];

    auto f = [&](int off)
    {
        int prev = a[0] + off;
        int cnt = off;
        rep(i, n - 1)
        {
            int d = 0;
            if (b[i] == 0)
            {
                if ((prev % 2) != (a[i + 1] % 2))
                    d = 1;
            }
            else
            {
                if ((prev % 2) == (a[i + 1] % 2))
                {
                    d = 1;
                }
            }
            cnt += d;
            prev = a[i + 1] + d;
        }
        return cnt;
    };

    cout << min(f(0), f(1)) << endl;

    return 0;
}
