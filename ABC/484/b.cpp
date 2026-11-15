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
    int k;
    cin >> k;

    int minBall = 10;
    bool is9 = false;
    rep(i, k)
    {
        int a;
        cin >> a;
        minBall = min(minBall, a);
        if (a == 9)
        {
            is9 = true;
        }
    }

    if (!is9)
        cout << -1 << endl;
    else
        cout << minBall << endl;

    return 0;
}
