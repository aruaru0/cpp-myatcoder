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
    rep(i, n) cin >> p[i];
    vector<int> q(n);
    rep(i, n) cin >> q[i];

    vector<int> z(n);
    rep(i, n) z[q[i] - 1] = i + 1;

    rep(i, n)
    {
        int x = p[z[i] - 1];
        cout << q[x - 1] << " ";
    }
    cout << endl;
    return 0;
}
