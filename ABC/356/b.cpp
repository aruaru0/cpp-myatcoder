#include <iostream>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    rep(i, m) cin >> a[i];

    vector<int> b(m);
    rep(i, n)
    {
        rep(j, m)
        {
            int x;
            cin >> x;
            b[j] += x;
        }
    }

    bool ok = true;
    rep(i, m) if (a[i] > b[i]) ok = false;
    cout << (ok ? "Yes" : "No") << endl;
}