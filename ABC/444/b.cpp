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

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int x = i; x > 0; x /= 10)
        {
            sum += x % 10;
        }
        if (sum == k)
        {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
