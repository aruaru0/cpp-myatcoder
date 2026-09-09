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

    bool ok = false;
    rep(i, n)
    {
        if (a[i] > b[i])
        {
            ok = true;
            break;
        }
    }

    if (ok)
    {
        cout << "Yes" << endl;
        const ll inf = 1e18;
        rep(i, n)
        {
            if (a[i] > b[i])
                cout << inf << " ";
            else
                cout << 1 << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
