#include <iostream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;
    vector<string> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    rep(i, n) rep(j, n) if (a[i][j] != b[i][j])
    {
        cout << i + 1 << " " << j + 1 << endl;
        return 0;
    }

    return 0;
}