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
    int n, K, T;
    cin >> n >> K >> T;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int cur = 0, cnt = 0;
    rep(i, n)
    {
        if (a[i] >= T)
        {
            break;
        }
        int diff = max(0, a[i] - cur);
        int c = (diff + K - 1) / K;
        cur += c * K;
        cnt += c;

        if (cur < a[i] + K)
        {
            cur = a[i] + K;
        }

        if (cur >= T)
        {
            break;
        }
    }

    int diff = max(0, T - cur);
    int c = (diff + K - 1) / K;

    cur += c * K;
    cnt += c;

    cout << cnt << endl;
    return 0;
}
