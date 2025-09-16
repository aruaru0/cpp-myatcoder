#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<ll, int>;

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
    vector<int> a(n), b(n), c(n);
    rep(i, n) cin >> a[i] >> b[i] >> c[i];

    priority_queue<P, vector<P>, greater<P>> pq;

    ll cur = 0;
    int cnt = 0;

    rep(i, n)
    {
        cnt += c[i];
        // cout << cnt << endl;
        while (k < cnt && pq.size() != 0)
        {
            auto [ti, num] = pq.top();
            pq.pop();
            cnt -= num;
            cur = ti;
        }
        cur = max(cur, (ll)a[i]);
        pq.push({cur + b[i], c[i]});
        cout << cur << endl;
    }

    return 0;
}
