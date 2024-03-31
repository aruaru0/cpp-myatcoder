#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a % k == 0)
        {
            cout << a / k << " ";
        }
    }
    cout << endl;
}
