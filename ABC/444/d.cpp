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

    const int size = 1e6;
    int mx = 0;
    vector<int> cnt(size, 0);
    for (auto e : a)
    {
        mx = max(mx, e);
        cnt[e]--;
        cnt[0]++;
    }

    rep(i, size - 1)
    {
        cnt[i + 1] += cnt[i];
    }

    rep(i, size - 1)
    {
        int d = cnt[i];
        cnt[i] = d % 10;
        cnt[i + 1] += d / 10;
    }

    // rep(i, mx)
    // {
    //     cout << cnt[i] << endl;
    // }

    bool flg = false;
    for (int i = size - 1; i >= 0; i--)
    {
        if (flg)
        {
            cout << cnt[i];
        }
        else
        {
            if (cnt[i])
            {
                flg = true;
                cout << cnt[i];
            }
        }
    }
    cout << endl;

    return 0;
}
