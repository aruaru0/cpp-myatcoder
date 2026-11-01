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
    int h, w, n, q;
    cin >> h >> w >> n >> q;

    vector<int> R(n), C(n);
    rep(i, n)
    {
        cin >> R[i] >> C[i];
    }

    sort(R.begin(), R.end());
    sort(C.begin(), C.end());

    auto cnt = [&](int l, int r, vector<int> &v)
    {
        return upper_bound(v.begin(), v.end(), r) -
               lower_bound(v.begin(), v.end(), l);
    };

    rep(qi, q)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
        {
            cout << cnt(l, r, R) << endl;
        }
        else
        {
            cout << cnt(l, r, C) << endl;
        }
    }

    return 0;
}
