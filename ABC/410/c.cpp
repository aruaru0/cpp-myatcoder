#include <iostream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, n) a[i] = i + 1;
    int spos = 0;

    rep(qi, q)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int p, x;
            cin >> p >> x;
            int pos = (spos + p - 1) % n;
            a[pos] = x;
        }
        else if (t == 2)
        {
            int p;
            cin >> p;
            int pos = (spos + p - 1) % n;
            cout << a[pos] << endl;
        }
        else
        {
            int k;
            cin >> k;
            spos = (spos + k) % n;
        }
    }
}