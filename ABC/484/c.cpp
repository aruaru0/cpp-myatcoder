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
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    int l = 0;
    rep(i, n)
    {
        if (a[i] != b[i])
        {
            l = i;
            break;
        }
    }

    int r = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] != b[i])
        {
            r = i;
            break;
        }
    }

    {
        bool ok = true;
        int m = r - l + 1;
        for (int i = 0; i < m; i++)
        {
            int ia = l + i;
            int ib = l + (i + 1) % m;
            // cout << a[ia] << " " << b[ib] << endl;
            if (a[ia] != b[ib])
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    {
        bool ok = true;
        int m = r - l + 1;
        for (int i = 0; i < m; i++)
        {
            int ib = l + i;
            int ia = l + (i + 1) % m;
            if (a[ia] != b[ib])
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}
