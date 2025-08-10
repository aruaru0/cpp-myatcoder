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
    string s;
    cin >> s;
    int n = s.size();

    double ans = 0;

    rep(i, n) for (int j = i + 2; j < n; j++)
    {
        if (s[i] == 't' && s[j] == 't')
        {
            int x = 0;
            for (int k = i; k <= j; k++)
            {
                if (s[k] == 't')
                    x++;
            }
            int t = j - i + 1;
            ans = max(ans, (double)(x - 2) / (t - 2));
        }
    }

    printf("%.20f\n", ans);

    return 0;
}
