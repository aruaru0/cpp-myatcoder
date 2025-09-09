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
    int N, K;
    cin >> N >> K;
    int n = 1 << N;

    int p = K / n;
    int q = K % n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = p;
    }

    auto f = [&](auto f, int l, int r, int cnt)
    {
        if (cnt == 0)
            return;
        if (l + 1 == r)
        {
            a[l] += cnt;
            return;
        }
        int mid = (l + r) / 2;
        f(f, l, mid, cnt / 2);
        f(f, mid, r, cnt - cnt / 2);
    };

    f(f, 0, n, q);

    cout << ((q == 0) ? 0 : 1) << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
