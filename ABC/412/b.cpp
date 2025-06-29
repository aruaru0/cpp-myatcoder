#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string s, t;
    cin >> s >> t;

    set<char> m;
    for (int i = 1; i < s.size(); i++)
    {
        // s[i]が大文字なら
        if (isupper(s[i]))
        {
            m.insert(s[i - 1]);
        }
    }

    for (auto e : m)
    {
        if (t.find(e) == string::npos)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
