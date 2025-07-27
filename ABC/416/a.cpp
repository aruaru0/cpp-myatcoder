#include <iostream>

using namespace std;

int main()
{
    int n, l, r;
    cin >> n >> l >> r;

    l--;

    string s;
    cin >> s;

    bool ok = true;
    for (int i = l; i < r; i++)
    {
        if (s[i] != 'o')
        {
            ok = false;
        }
    }

    if (ok)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}