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
    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int pre = -1;
    vector<int> c;
    rep(i, n)
    {
        if (a[i] != pre)
        {
            c.push_back(a[i]);
        }
        pre = a[i];
    }

    cout << c.size() << endl;
    rep(i, c.size()) cout << c[i] << " ";
    cout << endl;
}