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

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int cnt = 0;
    int cur = a[0];
    if (cur == k)
        cnt++;

    for (int i = 1; i < n; i++)
    {
        if (a[i] == k)
            cnt++;
        else if (a[i] < k && cur > k)
            cnt++;
        else if (a[i] > k && cur < k)
            cnt++;
        cur = a[i];
    }

    cout << cnt << endl;

    return 0;
}
