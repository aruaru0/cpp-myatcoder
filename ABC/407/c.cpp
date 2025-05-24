#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string s;
    cin >> s;

    int cnt = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        int d = s[i] - '0';
        int cur = cnt % 10;
        if (cur > d)
        {
            d += 10;
        }
        cnt += d - cur;
    }

    cout << cnt + s.size() << endl;
    return 0;
}
