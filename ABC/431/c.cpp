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
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> h(n);
    vector<int> b(m);
    rep(i, n) cin >> h[i];
    rep(i, m) cin >> b[i];

    sort(h.begin(), h.end());
    sort(b.begin(), b.end());

    int idx = 0, cnt = 0;
    rep(i, n)
    {
        while (idx < m && h[i] > b[idx])
            idx++;
        if (idx == m)
        {
            break;
        }
        idx++;
        cnt++;
    }

    if (cnt >= k)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
