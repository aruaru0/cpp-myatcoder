#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();

    while (s[n - 1] == '0')
    {
        n--;
    }
    if (s[n - 1] == '.')
    {
        n--;
    }

    cout << s.substr(0, n) << endl;
}