#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int cnt[26] = {};
    int mx = -1;
    for (int i = 0; i < s.size(); i++)
    {
        cnt[s[i] - 'a']++;
        mx = max(mx, cnt[s[i] - 'a']);
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (mx == cnt[s[i] - 'a'])
            continue;
        cout << s[i];
    }

    cout << endl;
}