#include <iostream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    int cnt = 0;
    // sに含まれる"ABC"の個数を数える
    rep(i, n - 2)
    {
        if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C')
        {
            cnt++;
        }
    }

    rep(qi, q)
    {
        int x;
        char c;
        cin >> x >> c;
        x--;
        for (int i = max(0, x - 2); i < min(n, x + 3); i++)
        {
            if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C')
            {
                cnt--;
            }
        }
        s[x] = c;
        for (int i = max(0, x - 2); i < min(n, x + 3); i++)
        {
            if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C')
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}