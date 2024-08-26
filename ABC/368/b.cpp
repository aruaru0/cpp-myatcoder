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
    rep(i, n) cin >> a[i];

    int cnt = 0;
    while (true)
    {
        sort(a.begin(), a.end(), std::greater<int>());
        if (a[1] <= 0)
            break;
        a[0]--;
        a[1]--;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
