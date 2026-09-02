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

    vector<int> b(n);
    b[0] = a[0] % k;
    rep(i, n - 1) b[i + 1] = (b[i] + a[i + 1]) % k;

    int cnt = 0;
    set<int> s;
    s.insert(0);
    rep(i, n)
    {
        if (s.find(b[i]) != s.end())
        {
            cnt++;
            s.clear();
        }
        s.insert(b[i]);
    }

    cout << cnt << endl;

    return 0;
}
