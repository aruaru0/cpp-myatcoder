#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    vector<int> b(q);

    rep(i, q)
    {
        int x;
        cin >> x;
        x--;
        if (x >= 0)
        {
            a[x]++;
            b[i] = x + 1;
        }
        else
        {
            int min_v = a[0];
            int min_pos = 0;
            rep(j, n)
            {
                if (min_v > a[j])
                {
                    min_v = a[j];
                    min_pos = j;
                }
            }
            a[min_pos]++;
            b[i] = min_pos + 1;
        }
    }

    rep(i, q)
    {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}
