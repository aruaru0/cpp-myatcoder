#include <iostream>
#include <map>

using namespace std;

int main()
{
    string s;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }

    if (mp['y'] == 1 && mp['a'] == 1 && mp['h'] == 1 && mp['o'] == 2)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}