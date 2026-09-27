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
    int n, d;
    cin >> n >> d;

    vector<int> x(n);
    rep(i, n)
    {
        cin >> x[i];
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        bool ok = true;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (abs(x[i] - x[j]) < d)
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            ans.push_back(i + 1);
        }
    }

    cout << ans.size() << "\n";

    for (int i = 0; i < (int)ans.size(); i++)
    {
        cout << ans[i] << (i + 1 == (int)ans.size() ? "" : " ");
    }
    cout << "\n";

    return 0;
}
