#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int w, b;
    cin >> w >> b;
    string s = "";
    for (int i = 0; i < 20; i++)
    {
        s += "wbwbwwbwbwbw";
    }

    int tot = w + b;
    rep(i, 20)
    {
        int ww = 0, bb = 0;
        rep(j, tot)
        {
            if (s[i + j] == 'w')
            {
                ww++;
            }
            else
            {
                bb++;
            }
        }
        // cout << i << " " << i + tot << endl;
        // cout << s.substr(i, tot) << " " << ww << " " << bb << endl;
        if ((ww == w) & (bb == b))
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}