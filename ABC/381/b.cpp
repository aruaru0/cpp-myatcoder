#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;

    vector<int> a(26);

    if (s.size() % 2 != 0)
    {
        cout << "No" << endl;
        return 0;
    }

    for (int i = 0; i < s.size(); i += 2)
    {
        if (s[i] != s[i + 1])
        {
            cout << "No" << endl;
            return 0;
        }
        a[s[i] - 'a']++;
        a[s[i + 1] - 'a']++;
    }

    for (auto e : a)
    {
        // cout << e << endl;
        if (e != 0 && e != 2)
        {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}