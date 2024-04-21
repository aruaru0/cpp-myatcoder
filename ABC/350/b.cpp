#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<bool> flg(n, true);
    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        t--;

        flg[t] = !flg[t];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += flg[i];
    }

    cout << ans << endl;
}