#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> a(n);
    rep(i, n)
    {
        cin >> p[i];
        a[i] = p[i];
    }
    // 大きい順にaをソート
    std::sort(a.begin(), a.end(), greater<int>());

    map<int, int> m;
    int prev = 0, cnt = 1;
    rep(i, n)
    {
        if (prev != a[i])
        {
            m[a[i]] = cnt;
        }
        prev = a[i];
        cnt++;
    }

    rep(i, n)
    {
        cout << m[p[i]] << endl;
    }

    return 0;
}
