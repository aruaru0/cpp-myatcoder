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
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << v[i] << (i + 1 == (int)v.size() ? "" : " ");
    }
    return os;
}

int main()
{
    int n;
    cin >> n;

    vector<int> a;
    for (int i = 1; i * i <= n; i++)
        a.push_back(i * i);

    vector<int> p(n + 1);
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i + 1; j < a.size(); j++)
        {
            if (a[i] + a[j] <= n)
            {
                p[a[i] + a[j]]++;
            }
        }
    }
    vector<int> ans;
    rep(i, n + 1)
    {
        if (p[i] == 1)
        {
            ans.push_back(i);
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    cout << ans << endl;

    return 0;
}
