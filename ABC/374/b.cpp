#include <iostream>

using namespace std;

int main()
{
    string s, t;

    cin >> s >> t;

    if (s.length() > t.length())
    {
        swap(s, t);
    }

    if (s == t)
    {
        cout << "0" << endl;
        return 0;
    }

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != t[i])
        {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << s.length() + 1 << endl;
}