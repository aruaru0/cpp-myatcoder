#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s;
    cin >> t;

    bool ok = true;
    for (int i = 0; i < n; i++)
    {
        if (t[i] == '*')
            continue;
        if (s[i] != t[i])
            ok = false;
    }

    if (ok)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}