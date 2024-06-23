#include <iostream>
#include <vector>
#include <set>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void solve()
{
    int N, A, M;
    cin >> N >> A >> M;

    vector<int> a;
    set<int> m;
    int tot = 0;
    ll sum = 0;
    while (1)
    {
        tot += A;
        int e = M - tot % M;
        e %= M;
        if (m.find(e) != m.end())
        {
            break;
        }
        m.insert(e);
        a.push_back(e);
        sum += e;
    }

    int x = N / a.size();
    int y = N % a.size();

    // cout << x << " " << y << endl;
    // rep(i, a.size()) cout << a[i] << " ";
    // cout << endl;
    ll ans = sum * x;
    for (int i = 0; i < y; i++)
    {
        ans += a[i];
    }

    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
}