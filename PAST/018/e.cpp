#include <iostream>
#include <vector>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> a(n);
    rep(i, n)
    {
        int c;
        cin >> c;
        rep(j, c)
        {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    }

    int ans = 0;
    rep(bit, 1 << n)
    {
        int cnt = 0;
        vector<int> b(101);
        rep(i, n)
        {
            if ((bit >> i) % 2)
            {
                cnt++;
                rep(j, a[i].size())
                {
                    b[a[i][j]]++;
                }
            }
        }

        if (cnt >= 2)
        {
            bool ok = true;
            for (int i = 0; i <= 100; i++)
            {
                if (i % 2 == 0 && b[i] == cnt)
                    ok = false;
            }
            if (ok)
                ans++;
        }
    }

    cout << ans << endl;
}