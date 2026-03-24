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
    rep(i, n)
    {
        cin >> a[i];
        a[i] %= k;
    }
    sort(a.begin(), a.end());

    deque<int> q;
    rep(i, n)
    {
        q.push_back(a[i]);
    }

    int ans = k;
    rep(i, n)
    {
        ans = min(ans, q.back() - q.front());
        q.push_back(q.front() + k);
        q.pop_front();
    }

    cout << ans << endl;

    return 0;
}
