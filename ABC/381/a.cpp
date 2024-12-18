#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    if (n % 2 == 0)
    {
        cout << "No" << endl;
        return 0;
    }

    int n2 = n / 2;

    for (int i = 0; i < n2; i++)
    {
        if (s[i] != '1')
        {
            cout << "No" << endl;
            return 0;
        }
    }
    if (s[n2] != '/')
    {
        cout << "No" << endl;
        return 0;
    }
    for (int i = n2 + 1; i < n; i++)
    {
        if (s[i] != '2')
        {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}