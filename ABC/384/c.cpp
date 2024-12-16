#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int score[5];
    rep(i, 5) cin >> score[i];

    int bit = 1 << 5;
    vector<P> ans;
    for (int b = 1; b < bit; b++)
    {
        int sum = 0;
        rep(i, 5)
        {
            if (b & (1 << i))
            {
                sum += score[4 - i];
            }
        }
        ans.push_back(P(sum, b));
    }

    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());

    for (auto [s, b] : ans)
    {
        // cout << s << " " << b << " :";
        for (int i = 4; i >= 0; i--)
        {
            if (b & (1 << i))
            {
                cout << char('E' - i);
            }
        }
        cout << endl;
    }
}