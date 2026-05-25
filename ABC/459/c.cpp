#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> h(n), c(1e6);
    c[0] = n;
    int l = 0;
    rep(qi, q)
    {
        int type, x;
        cin >> type >> x;
        if (type == 1)
        {
            x--;
            h[x]++;
            c[h[x]]++;
            if (c[l + 1] == n)
                l++;
        }
        else
        {
            cout << c[l + x] << endl;
        }
    }
    return 0;
}