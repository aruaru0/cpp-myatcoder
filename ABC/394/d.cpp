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

    string t = "";
    for (auto c : s)
    {
        t.push_back(c);
        while (t.size() > 1)
        {
            int n = t.size();
            if (t[n - 2] == '(' && t[n - 1] == ')')
            {
                t.pop_back();
                t.pop_back();
            }
            else if (t[n - 2] == '[' && t[n - 1] == ']')
            {
                t.pop_back();
                t.pop_back();
            }
            else if (t[n - 2] == '<' && t[n - 1] == '>')
            {
                t.pop_back();
                t.pop_back();
            }
            else
            {
                break;
            }
        }
    }

    if (t.size() == 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
