#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    int n, c;
    cin >> n >> c;
    vector<int> a(n);

    ll tot = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        tot += a[i];
    }

    if (c >= 1)
    {
        ll s = 0, m = 0;
        ll sel = 0;
        for (int i = 0; i < n; i++)
        {
            s += a[i];
            m = min(m, s);
            sel = max(sel, s - m);
        }
        tot += sel * (c - 1);
    }
    else
    {
        ll s = 0, m = 0;
        ll sel = 0;
        for (int i = 0; i < n; i++)
        {
            s += a[i];
            m = max(m, s);
            sel = min(sel, s - m);
        }
        tot += sel * (c - 1);
    }
    cout << tot << endl;
}