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
    string s, t;
    cin >> s >> t;

    auto f = [](string x, string y) -> int
    {
        int cnt = 0;
        rep(i, x.size())
        {
            int a = x[i] - '0';
            int b = y[i] - '0';
            cnt += (a - b + 10) % 10;
        }
        return cnt;
    };

    int ans = 1e9;
    rep(i, n - m + 1)
    {
        ans = min(ans, f(s.substr(i, m), t));
    }

    cout << ans << endl;
    return 0;
}
