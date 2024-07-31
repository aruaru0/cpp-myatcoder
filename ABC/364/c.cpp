#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> b(n);
    rep(i, n) cin >> b[i];

    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    int cnt_a = 0, cnt_b = 0;
    int tot_a = 0, tot_b = 0;
    rep(i, n)
    {
        tot_a += a[i];
        cnt_a++;
        if (tot_a > x)
        {
            break;
        }
    }
    rep(i, n)
    {
        tot_b += b[i];
        cnt_b++;
        if (tot_b > y)
        {
            break;
        }
    }

    cout << min(cnt_a, cnt_b) << endl;
}