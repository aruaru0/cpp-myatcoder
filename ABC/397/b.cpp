#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    string t;
    for (int i = 0; i < s.size(); i++)
    {
        if (t.size() % 2 == 0)
        {
            if (s[i] != 'i')
                t += 'i';
        }
        else
        {
            if (s[i] != 'o')
                t += 'o';
        }
        t += s[i];
    }
    if (t.size() % 2 == 1)
    {
        t += 'o';
    }

    // cout << t << endl;
    cout << t.size() - s.size() << endl;
}