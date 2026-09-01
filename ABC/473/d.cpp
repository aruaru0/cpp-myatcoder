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
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << v[i] << (i + 1 == (int)v.size() ? "" : " ");
    }
    return os;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n, 0);

    auto dfs = [&](auto dfs, int idx, int rem)
    {
        if (idx == n - 1)
        {
            if (rem % n == 0)
            {
                a[idx] = rem / n;
                cout << a << endl;
            }
            return;
        }

        int limit = rem / (idx + 1);

        for (int v = 0; v <= limit; v++)
        {
            a[idx] = v;
            dfs(dfs, idx + 1, rem - v * (idx + 1));
        }
    };

    dfs(dfs, 0, k);
}
