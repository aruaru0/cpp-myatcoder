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
    int n, k;
    cin >> n >> k;

    vector<int> a(k);
    int mx = 0;
    rep(i, n)
    {
        int x;
        cin >> x;
        a[x - 1]++;
        mx = max(mx, a[x - 1]);
    }

    int cnt = 0;
    rep(i, k) if (a[i] >= mx - 1) cnt++;
    cout << cnt << endl;
    return 0;
}
