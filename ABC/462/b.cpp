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

    vector<vector<int>> b(n);

    rep(i, n)
    {
        int k;
        cin >> k;
        rep(j, k)
        {
            int a;
            cin >> a;
            b[a - 1].push_back(i);
        }
    }

    rep(i, n)
    {
        cout << b[i].size() << " ";
        sort(b[i].begin(), b[i].end());
        for (auto e : b[i])
        {
            cout << e + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}
