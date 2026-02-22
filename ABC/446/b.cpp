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
    int n, m;
    cin >> n >> m;

    vector<bool> used(m + 1);
    rep(i, n)
    {
        int l;
        cin >> l;
        vector<int> x(l);
        rep(j, l)
        {
            cin >> x[j];
        }
        int sel = 0;
        for (auto e : x)
        {
            if (used[e] == false)
            {
                used[e] = true;
                sel = e;
                break;
            }
        }
        cout << sel << endl;
    }
    return 0;
}
