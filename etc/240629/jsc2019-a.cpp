#include <vector>
#include <iostream>

using namespace std;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    rep(i, n)
    {
        cin >> a[i];
    }
    rep(i, m)
    {
        cin >> b[i];
    }

    vector<P> d(2100000, P{-1, -1});

    rep(i, n) rep(j, m)
    {
        int tot = a[i] + b[j];
        if (d[tot].first != -1)
        {
            if (d[tot].first != i && d[tot].second != j)
            {
                cout << d[tot].first << " " << d[tot].second << " " << i << " " << j << endl;
                return 0;
            }
        }
        d[tot] = P{i, j};
    }

    cout << -1 << endl;
}