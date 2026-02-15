#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    if (s[0] == s[s.length() - 1])
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}