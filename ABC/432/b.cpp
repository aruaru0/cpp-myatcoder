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
    int X;
    cin >> X;

    vector<int> a;
    int zero_cnt = 0;
    while (X > 0)
    {
        if (X % 10 == 0)
        {
            zero_cnt++;
        }
        else
        {
            a.push_back(X % 10);
        }
        X /= 10;
    }

    sort(a.begin(), a.end());

    int ans = a[0];
    rep(i, zero_cnt) ans *= 10;

    for (int i = 1; i < a.size(); i++)
    {
        ans = ans * 10 + a[i];
    }

    cout << ans << endl;

    return 0;
}
