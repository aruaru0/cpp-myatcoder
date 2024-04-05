#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> b;
    for (auto e : a)
    {
        b.push_back(e % t);
        b.push_back(e % t + t);
    }

    sort(b.begin(), b.end());

    int d = 1e9 + 1;
    for (int i = 0; i < n; i++)
    {
        d = min(d, b[i + n - 1] - b[i]);
    }
    cout << d / 2 + d % 2 << endl;
}
