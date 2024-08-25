#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int pos = n - k;
    rep(i, n)
    {
        cout << a[pos] << " ";
        pos = (pos + 1) % n;
    }

    cout << endl;
}
