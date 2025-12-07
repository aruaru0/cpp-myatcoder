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
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> b(n + 1);
    rep(i, n) b[i + 1] = b[i] + a[i];

    int ans = 0;
    rep(l, n) for (int r = l; r < n; r++)
    {
        int sum = b[r + 1] - b[l];
        bool ok = true;
        for (int i = l; i <= r; i++)
        {
            if (sum % a[i] == 0)
            {
                ok = false;
            }
        }
        if (ok)
            ans++;
    }

    cout << ans << endl;
    return 0;
}
