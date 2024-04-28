#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const ll inf = 1e18;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    vector<int> route;
    vector<char> ab;
    int ai = 0, bi = 0;
    for (int i = 0; i < n * 2; i++)
    {
        bool flag;
        if (ai <= n - 1 && bi <= n - 1)
        {
            flag = a[ai] < b[bi];
        }
        else if (ai > n - 1)
        {
            flag = false;
        }
        else
        {
            flag = true;
        }
        if (flag)
        {
            route.push_back(a[ai]);
            ab.push_back(-1);
            ai++;
        }
        else
        {
            route.push_back(b[bi]);
            ab.push_back(+1);
            bi++;
        }
    }
    ll ans = inf;
    int coin = 0;
    ll leftminus = 0;
    ll max_r = route[route.size() - 1];

    rep(i, n * 2)
    {
        coin += ab[i];
        ans = min(ans, max_r + leftminus * 2 + max_r - route[i]);
        if (i != n * 2 - 1 && coin < 0)
        { // コインが不足する場合戻る必要がある
            leftminus += route[i + 1] - route[i];
        }
    }
    cout << ans << endl;
}