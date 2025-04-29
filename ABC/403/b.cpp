#include <iostream>

using namespace std;

int main()
{
    string t, u;
    cin >> t >> u;

    int nt, nu;
    nt = t.length();
    nu = u.length();

    for (int i = 0; i <= nt - nu; i++)
    {
        bool ok = true;
        for (int j = 0; j < nu; j++)
        {
            if (t[i + j] == '?')
                continue;
            if (t[i + j] != u[j])
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}