#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string s;
    cin >> s;

    set<string> st;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i + 1; j <= s.size(); j++)
        {
            // cout << s.substr(i, j - i) << endl;
            st.insert(s.substr(i, j - i));
        }
    }

    cout << st.size() << endl;
}