#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string s;
    cin >> s;
    vector<int> v(26);
    for (int i = 0; i < s.size(); i++)
    {
        v[s[i] - 'a']++;
    }
    map<int, int> mp;
    for (int i = 0; i < 26; i++)
    {
        mp[v[i]]++;
    }
    string ans = "Yes";
    for (auto x : mp)
    {
        if (x.first != 0 and x.second != 2)
        {
            ans = "No";
        }
    }
    cout << ans << endl;
}