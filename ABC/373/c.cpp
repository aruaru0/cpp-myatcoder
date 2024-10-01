#include <iostream>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;
    const int inf = 1e9;
    int ma = -inf, mb = -inf;
    rep(i, n)
    {
        int a;
        cin >> a;
        ma = max(ma, a);
    }
    rep(i, n)
    {
        int b;
        cin >> b;
        mb = max(mb, b);
    }
    cout << ma + mb << endl;
}