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

struct Stock
{
    int num;
    int day;
};

int solve()
{
    int n, d;
    cin >> n >> d;
    vector<int> A(n), B(n);
    rep(i, n)
    {
        cin >> A[i];
    }
    rep(i, n)
    {
        cin >> B[i];
    }

    deque<Stock> s;
    rep(i, n)
    {
        int a = A[i];
        int b = B[i];
        s.push_back({a, i});
        //
        while (b > 0)
        {
            if (s[0].num < b)
            {
                b -= s[0].num;
                s.pop_front();
            }
            else
            {
                s[0].num -= b;
                b = 0;
            }
        }
        // drop
        while (s.size() > 0 && i - s[0].day >= d)
        {
            s.pop_front();
        }
    }

    ll tot = 0;
    for (auto e : s)
    {
        tot += e.num;
    }
    cout << tot << endl;
    return 0;
}

int main()
{
    int t;
    cin >> t;
    rep(i, t)
    {
        solve();
    }
    return 0;
}