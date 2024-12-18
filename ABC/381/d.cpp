#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int f(vector<int> &a, int offset)
{
    int ret = 0;
    int pos = offset;

    map<int, int> m;

    for (int i = offset; i < a.size() - 1; i += 2)
    {
        if (a[i] != a[i + 1])
        {
            pos = i + 2;
            m = map<int, int>();
        }
        else
        {
            if (m.find(a[i]) != m.end())
            {
                pos = max(pos, m[a[i]] + 2);
            }
            m[a[i]] = i;
            ret = max(ret, 2 + i - pos);
        }
    }

    return ret;
}

int main()
{
    int n;
    cin >> n;
    vector<int> s(n);

    rep(i, n)
    {
        cin >> s[i];
    }

    int ans = f(s, 0);
    ans = max(ans, f(s, 1));

    cout << ans << endl;
}
