#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, string>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;

    vector<P> p(n);
    rep(i, n)
    {
        string s;
        cin >> s;
        p[i] = P{s.size(), s};
    }

    sort(p.begin(), p.end());

    rep(i, n)
    {
        cout << p[i].second;
    }
    cout << endl;

    return 0;
}
