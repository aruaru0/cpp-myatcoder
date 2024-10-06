#include <iostream>

using namespace std;

int main()
{
    string s;

    cin >> s;

    if (s.substr(s.length() - 3, 3) == "san")
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}