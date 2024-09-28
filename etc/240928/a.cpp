#include <iostream>
#include <vector>

const int MOD = 1000000007;
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    if (h > w)
    {
        swap(h, w);
    }

    vector<int> a;
    for (int i = 0; i < (1 << h); i++)
    {
        bool ok = true;
        for (int j = 1; j <= i; j <<= 1)
        {
            if ((i & j) != 0 && (i & (j << 1)) != 0)
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            a.push_back(i);
        }
    }

    int n = a.size();
    vector<vector<int>> b(w + 1, vector<int>(n));
    b[0][0] = 1;

    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                int t = (a[j] & a[k]) | ((a[j] << 1) & a[k]) | (a[j] & (a[k] << 1));
                if (t == 0)
                {
                    b[i + 1][k] = (b[i + 1][k] + b[i][j]) % MOD;
                }
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = (res + b[w][i]) % MOD;
    }

    cout << res - 1 << endl;
    return 0;
}