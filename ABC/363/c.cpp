#include <iostream>
#include <algorithm>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int cnt = 0;
    do
    {
        bool ok = true;
        rep(i, n - k + 1)
        {
            bool flg = true;
            rep(j, k)
            {
                if (s[i + j] != s[i + (k - 1) - j])
                {
                    flg = false;
                }
            }
            if (flg == true)
            {
                ok = false;
            }
        }
        if (ok)
        {
            cnt++;
        }
    } while (next_permutation(s.begin(), s.end()));

    cout << cnt << endl;
}