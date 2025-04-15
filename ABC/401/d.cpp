#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    rep(i, n)
    {
        if (s[i] == 'o')
        {
            if (i)
                s[i - 1] = '.';
            if (i + 1 < n)
                s[i + 1] = '.';
        }
    }

    int x = k - count(s.begin(), s.end(), 'o');

    vector<pair<int, int>> ps;
    {
        int i = 0;
        while (i < n)
        {
            if (s[i] == '?')
            {
                int l = i;
                while (i < n && s[i] == '?')
                    i++;
                int r = i;
                ps.emplace_back(l, r);
            }
            else
                i++;
        }
    }
    int mx = 0;
    for (auto [l, r] : ps)
        mx += (r - l + 1) / 2;

    if (x == 0)
    {
        for (auto [l, r] : ps)
        {
            for (int i = l; i < r; i++)
                s[i] = '.';
        }
    }
    else if (x == mx)
    {
        for (auto [l, r] : ps)
        {
            if ((r - l) % 2 == 0)
                continue;
            rep(i, r - l)
            {
                s[l + i] = "o."[i % 2];
            }
        }
    }

    cout << s << endl;
    return 0;
}