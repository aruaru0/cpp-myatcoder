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

void solve()
{
    int n;
    cin >> n;

    vector<P> p(n);
    ll sumW = 0;
    rep(i, n)
    {
        cin >> p[i].first >> p[i].second;
        sumW += p[i].first;
    }
    sort(p.begin(), p.end(), [](P a, P b)
         { return a.first + a.second > b.first + b.second; });

    ll sumPow = 0;
    rep(i, n)
    {
        sumW -= p[i].first;
        sumPow += p[i].second;
        if (sumW <= sumPow)
        {
            cout << n - (i + 1) << endl;
            break;
        }
    }
    return;
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
