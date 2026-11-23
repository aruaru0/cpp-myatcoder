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
    vector<int> c(n);
    rep(i, n) cin >> c[i];

    const int inf = 1e9;
    vector<int> ans(n, inf);

    int last = -1;
    for (int i = 1; i < n; i++)
    {
        if (c[i] != c[i - 1])
        {
            last = i - 1;
        }
        if (last != -1)
        {
            ans[i] = min(ans[i], i - last);
        }
    }
    last = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (c[i] != c[i + 1])
        {
            last = i + 1;
        }
        if (last != -1)
        {
            ans[i] = min(ans[i], last - i);
        }
    }

    rep(i, n)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
