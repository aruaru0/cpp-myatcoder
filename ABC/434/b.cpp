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
    int n, m;
    cin >> n >> m;

    vector<double> sum(m);
    vector<int> cnt(m);

    rep(i, n)
    {
        int a, b;
        cin >> a >> b;
        a--;
        sum[a] += b;
        cnt[a]++;
    }

    rep(i, m)
    {
        printf("%.10f\n", sum[i] / cnt[i]);
    }

    return 0;
}
