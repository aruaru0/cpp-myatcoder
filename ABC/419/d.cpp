#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s;
    cin >> t;

    vector<int> p(n + 1);
    rep(i, m)
    {
        int l, r;
        cin >> l >> r;
        p[l - 1] ^= 1;
        p[r] ^= 1;
    }

    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        int nxt = p[i] ^ cur;
        if (nxt)
        {
            s[i] = t[i];
        }
        cur = nxt;
    }
    cout << s << endl;
}
