#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, k;
    cin >> n >> k;

    ll tot = k * (k + 1) / 2;
    set<int> m;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a <= k && m.find(a) == m.end())
        {
            tot -= a;
            m.insert(a);
        }
    }

    cout << tot << endl;

    return 0;
}