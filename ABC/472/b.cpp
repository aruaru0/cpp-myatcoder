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

    vector<int> l(n);

    int sum = 0;
    rep(i, n)
    {
        cin >> l[i];
        sum += l[i];
    }

    int ans = sum;
    int sum2 = 0;
    rep(i, n)
    {
        sum2 += l[i];
        sum -= l[i];
        ans = min(ans, abs(sum2 - sum));
    }

    cout << ans << endl;

    return 0;
}
