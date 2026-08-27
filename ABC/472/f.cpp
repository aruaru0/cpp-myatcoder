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
    int n, q;
    cin >> n >> q;

    int n2 = n * 2;
    vector<ll> x(n2), y(n2);
    rep(i, n) cin >> x[i] >> y[i];
    rep(i, n)
    {
        x[n + i] = x[i];
        y[n + i] = y[i];
    }

    vector<ll> sum_a(n2, 0), sum_cx(n2, 0), sum_cy(n2, 0);
    for (int i = 1; i < n2; i++)
    {
        sum_a[i] = (x[i - 1] * y[i] - x[i] * y[i - 1]);
        sum_cx[i] = (x[i - 1] + x[i]) * sum_a[i];
        sum_cy[i] = (y[i - 1] + y[i]) * sum_a[i];
    }
    for (int i = 1; i < n2; i++)
    {
        sum_a[i] += sum_a[i - 1];
        sum_cx[i] += sum_cx[i - 1];
        sum_cy[i] += sum_cy[i - 1];
    }

    rep(qi, q)
    {
        int u, v;
        cin >> u >> v;
        if (u > v)
        {
            v += n;
        }
        u--;
        v--;

        double a_uv = x[v] * y[u] - x[u] * y[v];
        double cx_uv = (x[v] + x[u]) * a_uv;
        double cy_uv = (y[v] + y[u]) * a_uv;

        double a_diff = sum_a[v] - sum_a[u] + a_uv;
        double cx_diff = sum_cx[v] - sum_cx[u] + cx_uv;
        double cy_diff = sum_cy[v] - sum_cy[u] + cy_uv;

        double cx = cx_diff / (3.0 * a_diff);
        double cy = cy_diff / (3.0 * a_diff);
        printf("%.15f %.15f\n", cx, cy);
    }

    return 0;
}
