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

    vector<int> r(m), c(m);
    rep(i, m)
    {
        cin >> r[i] >> c[i];
        r[i]--;
        c[i]--;
    }

    vector<bool> usedR(n, false), usedC(n, false);
    int cnt = 0;

    for (int i = m - 1; i >= 0; i--)
    {
        if (usedR[r[i]] == false && usedC[c[i]] == false)
        {
            cnt++;
        }
        usedR[r[i]] = true;
        usedC[c[i]] = true;
    }

    cout << cnt << endl;

    return 0;
}
