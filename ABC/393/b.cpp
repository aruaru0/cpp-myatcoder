#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string s;
    cin >> s;

    int cnt = 0;
    rep(i, s.size())
    {
        if (s[i] == 'A')
        {
            for (int j = 1; j < s.size(); j++)
            {
                int bpos = i + j;
                int cpos = i + 2 * j;
                if (cpos < s.size())
                {
                    if (s[bpos] == 'B' && s[cpos] == 'C')
                    {
                        cnt++;
                    }
                }
            }
        }
    }

    cout << cnt << endl;
    return 0;
}
