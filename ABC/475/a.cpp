#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    string t = "";
    for (int i = 0; i < s.size(); i++)
    {
        t += s[i];
        if (i != s.size() - 1)
        {
            t += 'o';
        }
    }
    cout << t << endl;
}