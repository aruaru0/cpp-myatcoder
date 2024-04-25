#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main()
{
    string s;
    cin >> s;
    int n = s.size();

    vector<int> p(n, -1), t;
    rep(i, n)
    {
        if (s[i] == '(')
        {
            t.push_back(i);
        }
        else if (s[i] == ')')
        {
            int x = t.back();
            t.pop_back();
            p[x] = i;
            p[i] = x;
        }
    }

    s = s + ')';

    auto f = [&](auto f, int i, char mode)
    {
        if (mode == 'R')
        {
            if (s[i] == ')')
            {
                return;
            }
            else if (s[i] == '(')
            {
                f(f, p[i] - 1, 'L');
                f(f, p[i] + 1, 'R');
            }
            else
            {
                cout << s[i];
                f(f, i + 1, 'R');
            }
        }
        else
        {
            if (s[i] == '(')
            {
                return;
            }
            else if (s[i] == ')')
            {
                f(f, p[i] + 1, 'R');
                f(f, p[i] - 1, 'L');
            }
            else
            {
                auto v = s[i];
                if (isupper(v))
                {
                    v = tolower(v);
                }
                else
                {
                    v = toupper(v);
                }
                cout << v;
                f(f, i - 1, 'L');
            }
        }
    };

    f(f, 0, 'R');
    cout << endl;
}