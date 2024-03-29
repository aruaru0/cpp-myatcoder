#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int a;
    cin >> a;

    for (int i = 1; i <= 101; i++)
    {
        if (i * i * i == a)
        {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}
