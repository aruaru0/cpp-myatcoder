#include <iostream>
#include <vector>

using namespace std;
#define rep(i, j) for (int i = 0; i < j; i++)

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> a(N, vector<int>(0));

    rep(i, N)
    {
        rep(j, i + 1)
        {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    }

    int ans = 1;
    rep(n, N)
    {
        int i, j;
        i = ans - 1;
        j = n;
        if (i < j)
        {
            swap(i, j);
        }
        // cout << i << " " << j << endl;
        ans = a[i][j];
    }
    cout << ans << endl;
}