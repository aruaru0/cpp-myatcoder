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

    const int size = 2010;
    vector<vector<ll>> cnt(size, vector<ll>(size, 0));
    vector<vector<ll>> idx(size, vector<ll>(size, 0));

    rep(i, n)
    {
        int u, d, l, r;
        cin >> u >> d >> l >> r;
        u--, l--;
        cnt[u][l]++;
        cnt[u][r]--;
        cnt[d][l]--;
        cnt[d][r]++;
        idx[u][l] += i;
        idx[u][r] -= i;
        idx[d][l] -= i;
        idx[d][r] += i;
    }

    rep(i, size) for (int j = 1; j < size; j++)
    {
        cnt[i][j] += cnt[i][j - 1];
        idx[i][j] += idx[i][j - 1];
    }
    rep(j, size) for (int i = 1; i < size; i++)
    {
        cnt[i][j] += cnt[i - 1][j];
        idx[i][j] += idx[i - 1][j];
    }

    // rep(i, 10)
    // {
    //     rep(j, 10) cout << cnt[i][j] << " ";
    //     cout << endl;
    // }

    ll sum = 0;
    vector<int> num(n);
    rep(i, size) rep(j, size)
    {
        if (cnt[i][j] != 0)
        {
            sum++;
        }
        if (cnt[i][j] == 1)
        {
            num[idx[i][j]]++;
        }
    }

    rep(i, n)
    {
        cout << 2000 * 2000 - sum + num[i] << endl;
    }

    return 0;
}
