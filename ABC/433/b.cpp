#include <iostream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; (i) < (n); ++(i))

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    rep(i, n)
    {
        int ans = -1;
        for (int j = i; j >= 0; j--)
        {
            if (a[j] > a[i])
            {
                ans = j + 1;
                break;
            }
        }
        cout << ans << endl;
    }
}