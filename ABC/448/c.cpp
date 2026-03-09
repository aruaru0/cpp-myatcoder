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
    vector<int> a(n), p(n);
    rep(i, n)
    {
        int x;
        cin >> x;
        a[i] = x;
        p[i] = x;
    }

    sort(p.begin(), p.end());

    rep(qi, q)
    {
        int k;
        cin >> k;
        vector<int> x(k);
        rep(i, k)
        {
            int j;
            cin >> j;
            j--;
            x[i] = a[j];
        }
        sort(x.begin(), x.end());
        int idx = 0;
        rep(i, k)
        {
            if (x[i] == p[idx])
                idx++;
        }
        cout << p[idx] << endl;
    }

    return 0;
}
