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
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    rep(i, n) cin >> a[i + 1];

    int size = 31;
    vector<vector<int>> pos(size, vector<int>(n + 1));
    vector<vector<ll>> sum(size, vector<ll>(n + 1));

    rep(i, n + 1)
    {
        pos[0][i] = a[i];
        sum[0][i] = i;
    }

    rep(k, size - 1)
    {
        for (int i = 1; i <= n; i++)
        {
            pos[k + 1][i] = pos[k][pos[k][i]];
            sum[k + 1][i] = sum[k][i] + sum[k][pos[k][i]];
        }
    }

    rep(qi, q)
    {
        ll t, b;
        cin >> t >> b;

        int cur_pos = b;
        ll cur_sum = 0;
        rep(k, size)
        {
            if ((t >> k) % 2)
            {
                cur_sum += sum[k][cur_pos];
                cur_pos = pos[k][cur_pos];
            }
        }
        cout << cur_sum << endl;
    }

    return 0;
}
