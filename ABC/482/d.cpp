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
    vector<int> x(n);
    rep(i, n) cin >> x[i];

    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    rep(k, n)
    {
        int ans = 2e9;
        if (k > 0)
        {
            int t = max(x[k] - x[0], x[n - 1] - x[k - 1]) / 2;
            ans = min(ans, t);
        }
        if (k + 1 < n)
        {
            int t = max(x[k + 1] - x[0], x[n - 1] - x[k]) / 2;
            ans = min(ans, t);
        }
        cout << ans << endl;
    }

    return 0;
}
