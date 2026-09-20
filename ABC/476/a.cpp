#include <iostream>

using namespace std;

int main()
{
    string s;

    cin >> s;
    if (s[s.size() - 1] == 'e')
    {
        cout << s << "r" << endl;
    }
    else
    {
        cout << s << "er" << endl;
    }
}